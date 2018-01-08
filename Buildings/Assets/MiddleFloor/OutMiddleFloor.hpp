#ifndef _OUTMIDDLEFLOOR_
#define _OUTMIDDLEFLOOR_

#include "MiddleFloor.hpp"
#include <WallWithWindow.hpp>
#include <Decoration.hpp>


class OutMiddleFloor : public MiddleFloor
{
  public :
    OutMiddleFloor();
    ~OutMiddleFloor();
  protected :
    void setBuiltIn();
};

#endif
