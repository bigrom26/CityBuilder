#ifndef _BASICWALLWITHWINDOW_
#define _BASICWALLWITHWINDOW_

#include "WallWithWindow.hpp"
#include <Wall.hpp>
#include <FrameWindow.hpp>
#include <Window.hpp>
#include <Decoration.hpp>


class BasicWallWithWindow : public WallWithWindow
{
  public :
    BasicWallWithWindow();
    ~BasicWallWithWindow();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
