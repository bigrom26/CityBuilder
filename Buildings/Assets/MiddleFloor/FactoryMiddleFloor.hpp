#ifndef _FACTORYMIDDLEFLOOR_
#define _FACTORYMIDDLEFLOOR_

#include "MiddleFloor.hpp"
#include <WallWithWindow.hpp>
#include <Decoration.hpp>


class FactoryMiddleFloor : public MiddleFloor
{
  public :
    FactoryMiddleFloor();
    ~FactoryMiddleFloor();
  protected :
    void setBuiltIn();
};

#endif
