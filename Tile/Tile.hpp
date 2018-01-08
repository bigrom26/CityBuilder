#ifndef _TILE_
#define _TILE_

#include <StreetBloc.hpp>
#include "Asset.hpp"

/** @brief A tile */
class Tile : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Tile();
    ~Tile();
    void set();
    void turnLeft();
  protected :
    virtual void setBuiltIn() =0;
    bool north, south, east, west;
    float size;
};
#endif
