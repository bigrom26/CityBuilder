#ifndef _HAPPY_BOX_
#define _HAPPY_BOX_

#include "Object.hpp"
#include "../BoundingVolumes/AABB.hpp"

/** @brief A Happy Box */
class HappyBox : public Object
{
  public :
    /**
      @brief Constructor
      @param x1 abscisse of vertex 1
      @param y1 orderly of vertex 1
      @param z1 depth of vertex 1
      @param x2 abscisse of vertex 2
      @param y2 orderly of vertex 2
      @param z2 depth of vertex 2
      @param x3 abscisse of vertex 3
      @param y3 orderly of vertex 3
      @param z3 depth of vertex 3
    */
    HappyBox(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
    /** @brief rebuild the HappyBox with other parameters */
    void rebuild(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
  protected :
    void build() const;
    float abs1, ord1, dep1, abs2, ord2, dep2, abs3, ord3, dep3;
};

#endif
