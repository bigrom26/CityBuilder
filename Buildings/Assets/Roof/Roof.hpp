#ifndef _ROOF_
#define _ROOF_

#include "Asset.hpp"

/** @brief Represent a roof */
class Roof : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Roof();
    ~Roof();
    /**
      @brief Set params
      @param w The width of the roof
      @param d The depth of the roof
      @param sa The angle of the slope of the roof
    */
    void set(float w=5, float d=5, float sa=15);
	float getHeight()const;
  protected :
    virtual void setBuiltIn() =0;
    float width, depth, slope_angle;
};
#endif
