#ifndef _SKYSCRAPERBUILDING_
#define _SKYSCRAPERBUILDING_

#include "Building.hpp"
#include <BottomFloor.hpp>
#include <MiddleFloor.hpp>
#include <TopFloor.hpp>
#include <Guardrail.hpp>
#include <SatelliteDish.hpp>
#include <Cylinder.hpp>

class SkyscraperBuilding : public Building
{
  public :
    SkyscraperBuilding();
    ~SkyscraperBuilding();
  protected :
    void setBuiltIn();
};

#endif
