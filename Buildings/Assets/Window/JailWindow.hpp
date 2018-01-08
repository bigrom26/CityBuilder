#ifndef _JAILWINDOW_
#define _JAILWINDOW_

#include <Window.hpp>
#include <Cylinder.hpp>

class JailWindow : public Window
{
  public :
    JailWindow();
    ~JailWindow();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
