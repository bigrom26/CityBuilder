#include "Decoration.hpp"

Decoration::Decoration()
{
  type = "G_DECORATION";
}

Decoration::~Decoration()
{
  ;
}

void Decoration::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}


