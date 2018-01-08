#ifndef _CROSSROADS_
#define _CROSSROADS_

#include <AABB.hpp>
#include <StreetBloc.hpp>
#include "Tile.hpp"

class Crossroads : public Tile
{
  public :
    Crossroads();
    ~Crossroads();
  protected :
    void setBuiltIn();
};

#endif
