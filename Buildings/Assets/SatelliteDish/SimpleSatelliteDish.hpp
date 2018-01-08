#ifndef _SIMPLESATELLITEDISH_
#define _SIMPLESATELLITEDISH_

#include "SatelliteDish.hpp"
#include <Cylinder.hpp>


class SimpleSatelliteDish : public SatelliteDish
{
  public :
    SimpleSatelliteDish();
    ~SimpleSatelliteDish();
    virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
