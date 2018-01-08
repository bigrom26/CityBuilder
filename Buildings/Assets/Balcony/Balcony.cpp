#include "Balcony.hpp"

Balcony::Balcony()
{
  type = "G_BALCONY";
}

Balcony::~Balcony()
{
  ;
}

void Balcony::set(float w, float h, float d)
{
  width = w;
  height = h;
  depth = d;
  setBuiltIn();
  build();
}
