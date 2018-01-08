#ifndef _COMMERCIALBOTTOMFLOOR_
#define _COMMERCIALBOTTOMFLOOR_

#include "BottomFloor.hpp"
#include <Column.hpp>

class CommercialBottomFloor : public BottomFloor
{
  public :
    CommercialBottomFloor();
    ~CommercialBottomFloor();
  protected :
    void setBuiltIn();
};

#endif
