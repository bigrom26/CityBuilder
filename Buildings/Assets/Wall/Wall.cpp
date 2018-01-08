#include "Wall.hpp"

Wall::Wall()
{
  type = "G_WALL";
}

Wall::~Wall()
{
  ;
}

void Wall::set(float w, float h, float d)
{
  width = w;
  height = h;
  depth = d;
  setBuiltIn();
  build();
}


