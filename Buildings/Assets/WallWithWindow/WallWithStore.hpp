#ifndef _WALLWITHSTORE_
#define _WALLWITHSTORE_

#include "WallWithWindow.hpp"
#include <FrameWindow.hpp>
#include <Window.hpp>
#include <Wall.hpp>
#include <Decoration.hpp>
#include <HappyTriangle.hpp>

class WallWithStore : public WallWithWindow
{
  public :
    WallWithStore();
    ~WallWithStore();
	 virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
