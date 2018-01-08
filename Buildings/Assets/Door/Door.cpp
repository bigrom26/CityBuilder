#include "Door.hpp"

Door::Door()
{
  type = "G_DOOR";
}

Door::~Door()
{
  ;
}

void Door::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
