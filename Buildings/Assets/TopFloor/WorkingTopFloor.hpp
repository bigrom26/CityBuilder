#ifndef _WORKINGTOPFLOOR_
#define _WORKINGTOPFLOOR_

#include "TopFloor.hpp"
#include <HappyTriangle.hpp>

class WorkingTopFloor : public TopFloor
{
  public :
    WorkingTopFloor();
    ~WorkingTopFloor();
  protected :
    void setBuiltIn();
};

#endif
