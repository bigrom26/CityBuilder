#include "Chimney.hpp"

Chimney::Chimney()
{
  type = "G_CHIMNEY";
}

Chimney::~Chimney()
{
  ;
}

void Chimney::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
