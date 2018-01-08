#ifndef _AABB_
#define _AABB_

#include "BV.hpp"

/**
  @brief Axis-Aligned Bounding Box
*/
class AABB : public BV
{
  public :
    /**
      @brief Constructor
      @param h height
      @param w width
      @param d depth
    */
    AABB(float h, float w, float d);
    void paintGL() const;
  protected :
    float height, width, depth;
};

#endif
