#ifndef _SIMPLESTREETLIGHT_
#define _SIMPLESTREETLIGHT_

#include "Streetlight.hpp"
#include <HappyCylinder.hpp>
#include <Cylinder.hpp>


class SimpleStreetlight : public Streetlight
{
  public :
    SimpleStreetlight();
    ~SimpleStreetlight();
    virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
