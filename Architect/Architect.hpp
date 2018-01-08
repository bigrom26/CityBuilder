#ifndef _ARCHITECT_
#define _ARCHITECT_

#include <Factory.hpp>
#include <PlanParser.hpp>

class Architect
{
  public :
    Architect();
    ~Architect();
    Asset* get(string t);
    Asset* copy(Asset* a);
    void workWithPlan(string planFile);
   // void buildEnd();//signal used to synchonize the plan
  private :
    string getType(string t);
    Factory* f;
    PlanParser* p;
};

#endif
