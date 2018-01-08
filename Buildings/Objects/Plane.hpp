#ifndef _PLANE_
#define _PLANE_

#include "Object.hpp"
#include <AABB.hpp>

/** @brief A Plane */
class Plane : public Object
{
  public :
    /**
      @brief Constructor
      @param w width
      @param d depth
      @param ts is plane composed of one or two side ?
    */
    Plane(float w, float d, bool ts);
    /** @brief rebuild the Sphere with other parameters */
    void rebuild(float w, float d, bool ts);
  protected :
    void build() const;
    float width, depth;
    bool twoSide;
};

#endif
