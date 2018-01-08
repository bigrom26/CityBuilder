#ifndef _BASICTOPFLOOR_
#define _BASICTOPFLOOR_

#include "TopFloor.hpp"
#include <WallWithWindow.hpp>
#include <Roof.hpp>
#include <Decoration.hpp>


class BasicTopFloor : public TopFloor
{
  public :
    BasicTopFloor();
    ~BasicTopFloor();
  protected :
    void setBuiltIn();
};

#endif
