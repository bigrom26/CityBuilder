#ifndef _SIMPLEDOOR_
#define _SIMPLEDOOR_

#include "Door.hpp"

class SimpleDoor : public Door
{
  public :
    SimpleDoor();
    ~SimpleDoor();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
