#ifndef _BASICBOTTOMFLOOR_
#define _BASICBOTTOMFLOOR_

#include "BottomFloor.hpp"
#include <WallWithDoor.hpp>
#include <WallWithWindow.hpp>
#include <Decoration.hpp>


class BasicBottomFloor : public BottomFloor
{
  public :
    BasicBottomFloor();
    ~BasicBottomFloor();
  protected :
    void setBuiltIn();
};

#endif
