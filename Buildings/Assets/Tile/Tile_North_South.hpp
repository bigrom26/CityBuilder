#ifndef _TILE_NORTH_SOUTH_
#define _TILE_NORTH_SOUTH_

#include <AABB.hpp>
#include <StreetAlley.hpp>
#include "Tile.hpp"

class Tile_North_South : public Tile
{
  public :
    Tile_North_South();
    ~Tile_North_South();
  protected :
    void setBuiltIn();
};

#endif


