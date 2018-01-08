#ifndef _BASICBUILDING_
#define _BASICBUILDING_

#include "Building.hpp"
#include <BottomFloor.hpp>
#include <MiddleFloor.hpp>
#include <TopFloor.hpp>

class BasicBuilding : public Building
{
  public :
    BasicBuilding();
    ~BasicBuilding();
  protected :
    void setBuiltIn();
};

#endif
