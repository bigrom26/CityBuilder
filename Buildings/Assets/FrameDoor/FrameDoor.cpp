#include "FrameDoor.hpp"

FrameDoor::FrameDoor()
{
  type = "G_FRAMEDOOR";
}

FrameDoor::~FrameDoor()
{
  ;
}

void FrameDoor::set(float w, float h, float s)
{
  width = w;
  height = h;
  space = s;
  setBuiltIn();
  build();
}
