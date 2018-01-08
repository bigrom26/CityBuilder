#include "BusStop.hpp"

BusStop::BusStop()
{
  type = "G_BUSSTOP";
}

BusStop::~BusStop()
{
  ;
}

void BusStop::set(float w, float h, float d)
{
  width = w;
  height = h;
  depth = d;
  setBuiltIn();
  build();
}
