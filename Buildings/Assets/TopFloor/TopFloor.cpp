#include "TopFloor.hpp"

TopFloor::TopFloor()
{
  type = "G_TOPFLOOR";
}

TopFloor::~TopFloor()
{
  ;
}

void TopFloor::set(float w, float h, float d)
{
  width = w;
  height = h;
  depth = d;
  setBuiltIn();
  build();
}
