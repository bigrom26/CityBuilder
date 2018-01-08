#include "Architect.hpp"
#include <QtDebug>

Architect::Architect()
{
  f = new Factory();
  p = new PlanParser();
  //FIXME This will be synchronize with the map reading
  //p->setFile("../playground/planWWWTest.xml");
  //printf("Setting file\n");
}

Architect::~Architect()
{
  delete f;
  delete p;
}

Asset* Architect::copy(Asset* a)
{
  return a;
}

void Architect::workWithPlan(string planFile)
{
  p->setFile(planFile);
}

Asset* Architect::get(string t)
{
    Asset* a;
    //Ask for specific asset
    if(t[0]!='G'&& t[1]!='_')
    {
      a = f->getAsset(t);
      a->setArchitect(this);
      return a;
    }
    //Ask for generic asset, as to specified it via the plan
    else
    {
      //string s = p->getType(t);
      //printf("String returned : %s \n",s.c_str());
      a = f->getAsset(p->getType(t));
      a->setArchitect(this);
      return a;
    }

}
