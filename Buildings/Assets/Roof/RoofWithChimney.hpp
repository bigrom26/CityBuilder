#ifndef _ROOFWITHCHIMNEY_
#define _ROOFWITHCHIMNEY_

#include "SimpleRoof.hpp"

class RoofWithChimney : public SimpleRoof
{
  public :
    RoofWithChimney();
    ~RoofWithChimney();
  protected :
    void setBuiltIn();
};

#endif
