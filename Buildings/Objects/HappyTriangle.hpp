#ifndef _HAPPY_TRIANGLE_
#define _HAPPY_TRIANGLE_

#include "Object.hpp"
#include "../BoundingVolumes/AABB.hpp"

/** @brief A Happy Triangle */
class HappyTriangle : public Object
{
  public :
    /**
      @brief Constructor
      @param h height
      @param w width
      @param d depth
      @param a angle
    */
    HappyTriangle(float h, float w, float d, float a);
    /** @brief rebuild the HappyTriangle with other parameters */
    void rebuild(float h, float w, float d, float a);
  protected :
    void build() const;
    float height, width, depth, angle;
};

#endif
