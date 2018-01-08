#ifndef _WALLWITHBIGWINDOW_
#define _WALLWITHBIGWINDOW_

#include "WallWithWindow.hpp"
#include <Wall.hpp>
#include <FrameDoor.hpp>
#include <Window.hpp>
#include <Decoration.hpp>


class WallWithBigWindow : public WallWithWindow
{
  public :
    WallWithBigWindow();
    ~WallWithBigWindow();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
