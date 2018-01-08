#include "MiddleFloor.hpp"

MiddleFloor::MiddleFloor()
{
  type = "G_MIDDLEFLOOR";
}

MiddleFloor::~MiddleFloor()
{
  ;
}

void MiddleFloor::set(float w, float h, float d)
{
  width = w;
  height = h;
  depth = d;
  setBuiltIn();
  build();
}
