#ifndef _SIMPLEWINDOW_
#define _SIMPLEWINDOW_

#include "Window.hpp"
#include <Plane.hpp>

class SimpleWindow : public Window
{
  public :
    SimpleWindow();
    ~SimpleWindow();
  protected :
    void setBuiltIn();
};

#endif
