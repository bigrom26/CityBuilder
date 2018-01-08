#ifndef _WALLWITHINBALCONY_
#define _WALLWITHINBALCONY_

#include "WallWithWindow.hpp"
#include <Wall.hpp>
#include <FrameWindow.hpp>
#include <Window.hpp>
#include <Decoration.hpp>


class WallWithInBalcony : public WallWithWindow
{
  public :
    WallWithInBalcony();
    ~WallWithInBalcony();
	 virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
