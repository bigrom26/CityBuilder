#include "Streetlight.hpp"

Streetlight::Streetlight()
{
  type = "G_STREETLIGHT";
}

Streetlight::~Streetlight()
{
  ;
}

void Streetlight::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
