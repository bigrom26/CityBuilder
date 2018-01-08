#include "BarWindow.hpp"
#include <Plane.hpp>

BarWindow::BarWindow()
{
  style = CLASSIC;
}

void BarWindow::setBuiltIn()
{
  float depth = 0.05;
  bv = new AABB(height, depth, depth);
  Box* b1 = new Box(height, depth, depth);
  b1->translateOf(0.475, 0, 0);
  addObject(b1);
  Plane* p = new Plane(1, 1.5, true);
  p->rotateOf(90, 0, 0);
  p->setTransparency(0.25);
  addObject(p);
}

void BarWindow::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
	objects->at(1)->setQuality(3);
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(5);
	objects->at(1)->setQuality(8);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
  }
}
