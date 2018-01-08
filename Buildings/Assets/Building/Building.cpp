#include "Building.hpp"

Building::Building()
{
  type = "G_BUILDING";
}

Building::~Building()
{
  ;
}

void Building::set(float w, float d, int nl)
{
  width = w;
  depth = d;
  nbLevel = nl;
  setBuiltIn();
  build();
}
