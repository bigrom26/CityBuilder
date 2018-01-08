#ifndef _WORKINGDOOR_
#define _WORKINGDOOR_

#include "Door.hpp"

class WorkingDoor : public Door
{
  public :
    WorkingDoor();
    ~WorkingDoor();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
