#ifndef _PLANPARSER_
#define _PLANPARSER_

#include <qfile.h>
#include <qdom.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using std::string;

class Rdm{
  public :
    Rdm(string,string);
    ~Rdm(){};
    string getType();
    string getGType();
  private :
   string type;
   string gtype;
};

class PlanParser
{
  public :
    PlanParser();
    ~PlanParser();
    void setFile(string);
    void nextElement();
    void initAtFirstElement();
    string getType();
    void buildDoc(QDomElement);
    string getType(string tsearch);
    void addRdm(string, string);
    void clearRdm();
    string returnRdm(int);
    int searchRdm(string);
    void removeNode(QDomNode);
    bool isDeep();
    void goUp();
  private :
    int randomize(int*,int);
    QDomDocument doc;
    QDomDocument tmpDoc;
    QDomElement elem;
    std::vector<QDomElement>* selem;
    std::vector<Rdm*>* already_rdm;
    int depthSize;
    bool clear;
};

#endif
