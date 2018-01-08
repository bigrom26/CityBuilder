#include "Roof.hpp"

Roof::Roof()
{
  type = "G_ROOF";
}

Roof::~Roof()
{
  ;
}

float Roof::getHeight()const
{
  return tan(slope_angle*M_PI/180)*depth/2;
}

void Roof::set(float w, float d, float sa)
{
  width = w;
  depth = d;
  slope_angle = sa;
  setBuiltIn();
  build();
}
