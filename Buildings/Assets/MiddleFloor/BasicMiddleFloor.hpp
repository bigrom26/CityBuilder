#ifndef _BASICMIDDLEFLOOR_
#define _BASICMIDDLEFLOOR_

#include "MiddleFloor.hpp"
#include <WallWithWindow.hpp>
#include <Decoration.hpp>


class BasicMiddleFloor : public MiddleFloor
{
  public :
    BasicMiddleFloor();
    ~BasicMiddleFloor();
  protected :
    void setBuiltIn();
};

#endif
