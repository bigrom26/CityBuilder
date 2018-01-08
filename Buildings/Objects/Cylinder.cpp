#include "Cylinder.hpp"

Cylinder::Cylinder(float r, float h, float a, int q)
  : HappyCylinder(r, r, h, a, q)
{
  ;
}

void Cylinder::rebuild(float r, float h, float a, int q)
{
  HappyCylinder::rebuild(r, r, h, a, q);
}
