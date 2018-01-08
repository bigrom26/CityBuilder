#ifndef _BOTTOMFLOORWITHTWOFACADES_
#define _BOTTOMFLOORWITHTWOFACADES_

#include "BottomFloor.hpp"
#include <WallWithDoor.hpp>
#include <WallWithWindow.hpp>
#include <Wall.hpp>
#include <Decoration.hpp>

class BottomFloorWithTwoFacades : public BottomFloor
{
  public :
    BottomFloorWithTwoFacades();
    ~BottomFloorWithTwoFacades();
  protected :
    void setBuiltIn();
};

#endif
