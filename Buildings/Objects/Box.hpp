#ifndef _BOX_
#define _BOX_

#include "Object.hpp"
#include "../BoundingVolumes/AABB.hpp"

/** @brief A Box */
class Box : public Object
{
  public :
    /**
      @brief Constructor
      @param h height
      @param w width
      @param d depth
    */
    Box(float h, float w, float d);
    /** @brief rebuild the Sphere with other parameters */
    void rebuild(float h, float w, float d);
  protected :
    void build() const;
    float height, width, depth;
};

#endif
