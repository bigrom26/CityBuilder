#include "WallWithWindow.hpp"

WallWithWindow::WallWithWindow()
{
  type = "G_WALLWITHWINDOW";
}

WallWithWindow::~WallWithWindow()
{
  ;
}

void WallWithWindow::set(float w, float h)
{
  width = w;
  height = h;
  setBuiltIn();
  build();
}
