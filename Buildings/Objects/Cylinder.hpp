#ifndef _CYLINDER_
#define _CYLINDER_

#include "HappyCylinder.hpp"

/** @brief A Cylinder */
class Cylinder : public HappyCylinder
{
  public :
    /**
      @brief Constructor
      @param r radius
      @param h height
      @param a angle of piece of Cylinder
      @param q Quality (default = 20)
    */
    Cylinder(float r, float h, float a=2*M_PI, int q = 20);
    /** @brief rebuild with other parameters */
    void rebuild(float r, float h, float a, int q);
  private :
    void rebuild(float r1, float r2, float h, float a, int q);
};

#endif
