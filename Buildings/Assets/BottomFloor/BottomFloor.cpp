#include "BottomFloor.hpp"

BottomFloor::BottomFloor()
{
  type = "G_BOTTOMFLOOR";
}

BottomFloor::~BottomFloor()
{
  ;
}

void BottomFloor::set(float w, float h, float d)
{
  width = w;
  height = h;
  depth = d;
  setBuiltIn();
  build();
}
