#ifndef _BASICWALL_
#define _BASICWALL_

#include "Wall.hpp"


class BasicWall : public Wall
{
  public :
    BasicWall();
    ~BasicWall();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
