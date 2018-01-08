#ifndef _DOORWITHHOLE_
#define _DOORWITHHOLE_

#include "Door.hpp"

class DoorWithHole : public Door
{
  public :
    DoorWithHole();
    ~DoorWithHole();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
