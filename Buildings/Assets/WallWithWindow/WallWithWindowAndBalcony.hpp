#ifndef _WALLWITHWINDOWANDBALCONY_
#define _WALLWITHWINDOWANDBALCONY_

#include "WallWithWindow.hpp"
#include <FrameDoor.hpp>
#include <Wall.hpp>
#include <Decoration.hpp>
#include <Window.hpp>
#include <Balcony.hpp>


class WallWithWindowAndBalcony : public WallWithWindow
{
  public :
    WallWithWindowAndBalcony();
    ~WallWithWindowAndBalcony();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
