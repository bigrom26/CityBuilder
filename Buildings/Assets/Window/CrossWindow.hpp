#ifndef _CROSSWINDOW_
#define _CROSSWINDOW_

#include "Window.hpp"
#include <Box.hpp>
#include <Plane.hpp>

class CrossWindow : public Window
{
  public :
    CrossWindow();
    ~CrossWindow();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
