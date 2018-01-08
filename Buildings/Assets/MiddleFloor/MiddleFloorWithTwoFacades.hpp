#ifndef _MIDDLEFLOORWITHTWOFACADES_
#define _MIDDLEFLOORWITHTWOFACADES_

#include "MiddleFloor.hpp"
#include <WallWithWindow.hpp>
#include <Wall.hpp>
#include <Decoration.hpp>


class MiddleFloorWithTwoFacades : public MiddleFloor
{
  public :
    MiddleFloorWithTwoFacades();
    ~MiddleFloorWithTwoFacades();
  protected :
    void setBuiltIn();
};

#endif
