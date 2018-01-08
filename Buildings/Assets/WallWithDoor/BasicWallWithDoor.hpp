#ifndef _BASICWALLWITHDOOR_
#define _BASICWALLWITHDOOR_

#include "Door.hpp"
#include "FrameDoor.hpp"
#include "WallWithWindow.hpp"
#include "WallWithDoor.hpp"


class BasicWallWithDoor : public WallWithDoor
{
  public :
    BasicWallWithDoor();
    ~BasicWallWithDoor();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
