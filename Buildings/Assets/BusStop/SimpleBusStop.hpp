#ifndef _SIMPLEBUSSTOP_
#define _SIMPLEBUSSTOP_

#include "BusStop.hpp"
#include <Cylinder.hpp>
#include <Box.hpp>

class SimpleBusStop : public BusStop
{
  public :
    SimpleBusStop();
    ~SimpleBusStop();
  protected :
    void setBuiltIn();
};

#endif
