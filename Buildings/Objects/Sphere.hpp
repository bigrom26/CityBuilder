#ifndef _SPHERE_
#define _SPHERE_

#include "Object.hpp"
#include "../BoundingVolumes/BSphere.hpp"

/** @brief A Sphere */
class Sphere : public Object
{
  public :
    /**
      @brief Constructor
      @param r Radius
      @param q Quality (default = 20)
    */
    Sphere(float r, int q = 20);
    /** @brief rebuild the Sphere with other parameters */
    void rebuild(float r, int q);
  protected :
    void build() const;
    float radius;
    int quality;
};

#endif
