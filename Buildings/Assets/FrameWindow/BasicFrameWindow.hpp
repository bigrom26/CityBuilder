#ifndef _BASICFRAMEWINDOW_
#define _BASICFRAMEWINDOW_

#include "FrameWindow.hpp"

class BasicFrameWindow : public FrameWindow
{
  public :
    BasicFrameWindow();
    ~BasicFrameWindow();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
