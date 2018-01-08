#include "Pavement.hpp"

Pavement::Pavement()
{
  type = "G_PAVEMENT";
}

Pavement::~Pavement()
{
  ;
}

void Pavement::set(float w, float d, int nr, float h)
{
  width = w;
  depth = d;
  height = h;
  nbRound = nr;
  setBuiltIn();
  build();
}
