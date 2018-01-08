#ifndef _FRAMEDOORWITHTRIANGLE_
#define _FRAMEDOORWITHTRIANGLE_

#include "BasicFrameDoor.hpp"
#include <HappyTriangle.hpp>

class FrameDoorWithTriangle : public BasicFrameDoor
{
  public :
    FrameDoorWithTriangle();
    ~FrameDoorWithTriangle();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
