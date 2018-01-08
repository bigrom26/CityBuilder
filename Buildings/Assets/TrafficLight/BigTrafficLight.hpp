#ifndef _BIGTRAFFICLIGHT_
#define _BIGTRAFFICLIGHT_

#include "TrafficLight.hpp"
#include <Box.hpp>
#include <HappyTriangle.hpp>


class BigTrafficLight : public TrafficLight
{
  public :
    BigTrafficLight();
    ~BigTrafficLight();
  protected :
    void setBuiltIn();
};

#endif
