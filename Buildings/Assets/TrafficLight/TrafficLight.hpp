#ifndef _TRAFFICLIGHT_
#define _TRAFFICLIGHT_

#include <Asset.hpp>

/** @brief Represent a traffic light */
class TrafficLight : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    TrafficLight();
    ~TrafficLight();
    /**
      @brief Set params
      @param w The width of the traffic light
      @param h The height of the traffic light
    */
    void set(float w=0.3, float h=3);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
