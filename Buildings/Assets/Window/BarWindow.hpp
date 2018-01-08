#ifndef _BARWINDOW_
#define _BARWINDOW_

#include "Window.hpp"
#include <Box.hpp>

class BarWindow : public Window
{
  public :
    BarWindow();
    ~BarWindow();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
