#ifndef _BUSSTOP_
#define _BUSSTOP_

#include <Asset.hpp>

/** @brief Represent a bus stop */
class BusStop : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    BusStop();
    ~BusStop();
    /**
      @brief Set params
      @param w The width of the bus stop
      @param h The height of the bus stop
      @param d The depth of the bus stop
    */
    void set(float w=4, float h=2.5, float d=1.5);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, depth;
};
#endif
