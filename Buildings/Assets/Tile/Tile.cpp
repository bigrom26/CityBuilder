#include "Tile.hpp"

Tile::Tile()
  : north(false), south(false), east(false), west(false)
{
  size = 50;
}

Tile::~Tile()
{
  ;
}

void Tile::set()
{
  setBuiltIn();
  build();
}

void Tile::turnLeft()
{
  bool oldNorth = north;
  north = east;
  east = south;
  south = west;
  west = oldNorth;
  rotateOf(0,0,90);
  if(rz == 90)
    translateOf(size, 0, 0);
  else if(rz == 180)
    translateOf(0, size, 0);
  else if(rz == 270)
    translateOf(-size, 0, 0);
}
