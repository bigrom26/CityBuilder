#ifndef _SIMPLETRAFFICLIGHT_
#define _SIMPLETRAFFICLIGHT_

#include "TrafficLight.hpp"
#include <Box.hpp>
#include <Cylinder.hpp>
#include <HappyTriangle.hpp>


class SimpleTrafficLight : public TrafficLight
{
  public :
    SimpleTrafficLight();
    ~SimpleTrafficLight();
  protected :
    void setBuiltIn();
};

#endif
