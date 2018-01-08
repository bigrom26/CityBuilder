#ifndef _SATELLITEDISH_
#define _SATELLITEDISH_

#include <Asset.hpp>

/** @brief Represent a satellite dish */
class SatelliteDish : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    SatelliteDish();
    ~SatelliteDish();
    /**
      @brief Set params
      @param w The width of the satellite dish
      @param h The height of the satellite dish
    */
    void set(float w=0.5, float h=1);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
