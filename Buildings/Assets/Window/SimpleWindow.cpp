#include "SimpleWindow.hpp"

SimpleWindow::SimpleWindow()
{
  style = CLASSIC;
}

void SimpleWindow::setBuiltIn()
{
  bv = new AABB(height, width, 0.05);
  Plane* p = new Plane(width, height, true);
  p->rotateOf(90, 0, 0);
  p->setTransparency(0.25);
  addObject(p);
}
