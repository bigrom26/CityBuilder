#ifndef _FACTORYTOPFLOOR_
#define _FACTORYTOPFLOOR_

#include "TopFloor.hpp"
#include <WallWithWindow.hpp>
#include <Roof.hpp>
#include <Decoration.hpp>


class FactoryTopFloor : public TopFloor
{
  public :
    FactoryTopFloor();
    ~FactoryTopFloor();
  protected :
    void setBuiltIn();
};

#endif
