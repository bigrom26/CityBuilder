#include "PlanParser.hpp"

PlanParser::PlanParser()
{
  srand(time(NULL));
  depthSize=0;
  selem = new std::vector<QDomElement>(5);
  already_rdm = new std::vector<Rdm*>(5);
}

PlanParser::~PlanParser()
{
}

void PlanParser::setFile(string file)
{
  const char* str = file.c_str();
  QString q(str);
  QFile f(q);
  if(!f.open(QIODevice::ReadOnly))
    printf("Error : unable to open plan locate in %s\n",file.c_str());
  doc.setContent(&f);
  f.close();
  elem = doc.documentElement();
 // printf("Loaded %s\n",elem.tagName().toStdString().c_str());

  //clean vectors
  clearRdm();
  clear = true;
  selem->clear();
}

void PlanParser::initAtFirstElement()
{
  elem = doc.documentElement().firstChild().toElement();
}

void PlanParser::nextElement()
{
  elem = elem.nextSibling().toElement();
}

string PlanParser::getType()
{
  if(elem.hasAttribute("type"))
    return elem.attribute("type").toStdString();
  else return "error";
}

void printChilds(QDomNodeList l)
{
  for(unsigned int i = 0;i<l.length();i++)
  {
    printf("Child = %s\n",l.item(i).toElement().tagName().toStdString().c_str());
  }
}

void PlanParser::buildDoc(QDomElement e)
{
  QFile f(e.attribute("link"));
  if(!f.open(QIODevice::ReadOnly))
    printf("Error : unable to open plan locate in %s\n",e.attribute("link").toStdString().c_str());
  tmpDoc.setContent(&f);
  f.close();
  QDomNodeList l = tmpDoc.documentElement().childNodes();
  QDomNode n;
  while(!l.isEmpty())
  {
    n=e.appendChild(l.item(0));
    if(n.isNull())
	printf("AppendChild failuire\n");;
  }
}

string PlanParser::getType(string tsearch)
{
  
  //printf("Searchin for %s, waiting in %s\n",tsearch.c_str(),elem.tagName().toStdString().c_str());
  QDomNodeList l = elem.elementsByTagName(QString(tsearch.c_str()));
  //FIXME Add id for more same type search
  //Add every step we look for the flag rdm. If it's 1, mean that the rdm vector has to been cleared
  if(!l.isEmpty())
  {
    if(l.item(0).toElement().hasAttribute("random"))
    {
	if(l.item(0).toElement().attribute("random").toInt() == 1 && clear)
	{
	  clearRdm();
	  clear=false;
	}
	else if(l.item(0).toElement().attribute("random").toInt() == 0)
	{
	  clearRdm();
	  clear=true;
	}

    }
    if(l.item(0).hasChildNodes())
    {
      //if there only one childNodes no random to make
      l = l.item(0).childNodes();
     // printChilds(l);
      if(l.length()==1)
      {
	  
	  if(l.item(0).toElement().hasAttribute("link"))
	  {
	    //building the rest of the document if necessary
	    if(!l.item(0).toElement().hasChildNodes())
	    {
	      buildDoc(l.item(0).toElement());
	    }
	    if(l.item(0).toElement().hasChildNodes())
	    {
	      depthSize++;
	      selem->push_back(elem);
	      elem = l.item(0).toElement();
	    }
	    //printf("--> %s and then %s\n",elem.tagName().toStdString().c_str(),elem.firstChild().toElement().tagName().toStdString().c_str());
	    return l.item(0).toElement().tagName().toStdString();
	  }
	  else
	  {
	    return l.item(0).toElement().tagName().toStdString();
	  }
      }
      else
      {
	  //need to randomize the selection using the weight attribute
	  //but before randomizing we make sur we have not choosen in the past by looking into the rdm vector
	  int res = searchRdm(tsearch);
	  if(res<0)	  
	  {
	    int weight[l.length()],i;
	    i=0;
	    for(unsigned int i = 0;i<l.length();i++)
	    {
	      weight[i] = l.item(i).toElement().attribute("weight").toInt();
	    }
	    unsigned int selected = randomize(weight,l.length());
	   //write into the vector rdm the selection made
	    addRdm(l.item(selected).toElement().tagName().toStdString(),tsearch);
	    if(l.item(selected).toElement().hasAttribute("link"))
	    {
		//building the rest of the document if necessary
		if(!l.item(selected).toElement().hasChildNodes())
		  buildDoc(l.item(selected).toElement());
		if(l.item(selected).toElement().hasChildNodes())
		  {
		    depthSize++;
		    selem->push_back(elem);
		    elem = l.item(selected).toElement();
		  }
		return l.item(selected).toElement().tagName().toStdString();
	    }
	    else
	    {
	      return l.item(selected).toElement().tagName().toStdString();
	    }
	  }
	  else
	  {
	      //build if necessary
	      for(unsigned int i = 0; i<l.length();i++)
	      {
		  if(l.item(i).toElement().tagName().toStdString().compare(returnRdm(res))==0)
		  {
		    //build if necessary
		    if(l.item(i).toElement().hasAttribute("link"))
		    {
		      //building the rest of the document if necessary
		      if(!l.item(i).toElement().hasChildNodes())
			buildDoc(l.item(i).toElement());
		      if(l.item(i).toElement().hasChildNodes())
		      {
			depthSize++;
			selem->push_back(elem);
			elem = l.item(i).toElement();
		      }
		    }
		  }
	      }
	      //printf("Returned : %s\n",returnRdm(res).c_str());
	      return returnRdm(res);
	  }
      }
    }
  }
  else
  {
    //No matches. If we're "deep" we go up once and search again.
    if(isDeep())
    {
      goUp();
      return getType(tsearch);
    }
    return "Parsing error : type ["+tsearch+"] not found";
  }
    
  return "Parsing error";
}

void PlanParser::removeNode(QDomNode n)
{
  n.parentNode().removeChild(n);
}

void PlanParser::addRdm(string t, string gtype)
{
  already_rdm->push_back(new Rdm(t,gtype));
}

void PlanParser::clearRdm()
{
  already_rdm->clear();
}

int PlanParser::searchRdm(string gt)
{
  for(unsigned int i = 0 ; i<already_rdm->size();i++)
  {
    if(already_rdm->at(i)->getGType().compare(gt)==0)
      return i;
  }
  return -1;
}

string PlanParser::returnRdm(int i)
{
  return already_rdm->at(i)->getType();
}

bool PlanParser::isDeep()
{
  if(depthSize>0)
    return true;
  return false;
}

void PlanParser::goUp()
{
  if(depthSize>0)
  {
    depthSize--;
    elem = selem->back();
    selem->pop_back();
  }
}

int PlanParser::randomize(int* weigth,int length)
{
  int hrand = -1;
  int temphrand = -1;
  int winner = -1;
  int temp;
  for(int i = 0;i<length;i++)
  {
    temp = weigth[i];
    temphrand = (int)rand()%temp;
    if(temphrand > hrand)
    {
      hrand = temphrand;
      winner = i;
    }
  }
  return winner;
}

//RDM

Rdm::Rdm(string t, string gt)
{
  type = t;
  gtype = gt;
}

string Rdm::getType()
{
  return type;
}

string Rdm::getGType()
{
   return gtype;
}