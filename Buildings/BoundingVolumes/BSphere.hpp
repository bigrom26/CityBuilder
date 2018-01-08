#ifndef _BSPHERE_
#define _BSPHERE_

#include "BV.hpp"

/**
  @brief Bounding Sphere
*/
class BSphere : public BV
{
  public :
    BSphere(float r);
    void paintGL() const;
  protected :
    float radius;
};

#endif
 