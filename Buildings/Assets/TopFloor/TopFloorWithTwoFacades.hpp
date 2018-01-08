#ifndef _TOPFLOORWITHTWOFACADES_
#define _TOPFLOORWITHTWOFACADES_

#include "TopFloor.hpp"
#include <WallWithWindow.hpp>
#include <Wall.hpp>
#include <Roof.hpp>
#include <Decoration.hpp>


class TopFloorWithTwoFacades : public TopFloor
{
  public :
    TopFloorWithTwoFacades();
    ~TopFloorWithTwoFacades();
  protected :
    void setBuiltIn();
};

#endif
