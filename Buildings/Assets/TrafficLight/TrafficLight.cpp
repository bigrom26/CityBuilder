#include "TrafficLight.hpp"

TrafficLight::TrafficLight()
{
  type = "G_TRAFFICLIGHT";
}

TrafficLight::~TrafficLight()
{
  ;
}

void TrafficLight::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
