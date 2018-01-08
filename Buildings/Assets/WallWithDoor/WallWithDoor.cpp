#include "WallWithDoor.hpp"

WallWithDoor::WallWithDoor()
{
  type = "G_WALLWITHDOOR";
}

WallWithDoor::~WallWithDoor()
{
  ;
}

void WallWithDoor::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
