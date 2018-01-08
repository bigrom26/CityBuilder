#include "SatelliteDish.hpp"

SatelliteDish::SatelliteDish()
{
  type = "G_SATELLITEDISH";
}

SatelliteDish::~SatelliteDish()
{
  ;
}

void SatelliteDish::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
