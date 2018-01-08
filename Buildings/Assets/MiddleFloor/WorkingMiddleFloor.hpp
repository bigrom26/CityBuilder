#ifndef _WORKINGMIDDLEFLOOR_
#define _WORKINGMIDDLEFLOOR_

#include "MiddleFloor.hpp"


class WorkingMiddleFloor : public MiddleFloor
{
  public :
    WorkingMiddleFloor();
    ~WorkingMiddleFloor();
  protected :
    void setBuiltIn();
};

#endif
