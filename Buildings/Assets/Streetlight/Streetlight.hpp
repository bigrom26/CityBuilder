#ifndef _STREETLIGHT_
#define _STREETLIGHT_

#include "Asset.hpp"

/** @brief Represent a streetlight */
class Streetlight : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Streetlight();
    ~Streetlight();
    /**
      @brief Set params
      @param w The width of the streetlight
      @param h The height of the streetlight
    */
    void set(float w=0.5, float h=3);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
