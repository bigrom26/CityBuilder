#include "FrameWindow.hpp"

FrameWindow::FrameWindow()
{
  type = "G_FRAMEWINDOW";
}

FrameWindow::~FrameWindow()
{
  ;
}

void FrameWindow::set(float w, float h, float s)
{
  width = w;
  height = h;
  space = s;
  setBuiltIn();
  build();
}
