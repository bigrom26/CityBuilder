#ifndef _CONE_
#define _CONE_

#include "Object.hpp"
#include "../BoundingVolumes/AABB.hpp"

/** @brief A Cone */
class Cone : public Object
{
  public :
    /**
      @brief Constructor
      @param r Radius
      @param h height
      @param q Quality (default = 20)
    */
    Cone(float r, float h, int q = 20);
    /** @brief rebuild with other parameters */
    void rebuild(float r, float h, int q);
  protected :
    void build() const;
    float radius, height;
    int quality;
};

#endif
