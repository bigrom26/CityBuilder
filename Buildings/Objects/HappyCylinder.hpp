#ifndef _HAPPYCYLINDER_
#define _HAPPYCYLINDER_

#include "Object.hpp"
#include "../BoundingVolumes/AABB.hpp"

/** @brief A cut down Cone */
class HappyCylinder : public Object
{
  public :
    /**
      @brief Constructor
      @param r1 bottom radius
      @param r2 top radius
      @param h height
      @param a angle of piece of Cylinder
      @param q Quality (default = 20)
    */
    HappyCylinder(float r1, float r2, float h, float a=2*M_PI, int q = 20);
    /** @brief rebuild with other parameters */
    void rebuild(float r1, float r2, float h, float a, int q);
    virtual void setQuality(int q);
  protected :
    void build() const;
    float radius1, radius2, height, angle;
    int quality;
};

#endif
