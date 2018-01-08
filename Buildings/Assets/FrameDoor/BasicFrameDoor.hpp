#ifndef _BASICFRAMEDOOR_
#define _BASICFRAMEDOOR_

#include "FrameDoor.hpp"

class BasicFrameDoor : public FrameDoor
{
  public :
    BasicFrameDoor();
    ~BasicFrameDoor();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
