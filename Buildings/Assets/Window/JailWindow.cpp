#include "JailWindow.hpp"
#include <Plane.hpp>

JailWindow::JailWindow()
{
  style = WESTERN;
}

void JailWindow::setBuiltIn()
{
  bv = new AABB(height, width, 0.07);
  Cylinder* c1 = new Cylinder(0.07, height, 8);
  c1->translateOf(width/3.0, 0, 0);
  Cylinder* c2 = new Cylinder(0.07, height, 8);
  c2->translateOf(2.0*width/3.0, 0, 0);
  addObject(c1);
  addObject(c2);
  Plane* p = new Plane(width, height, true);
  p->rotateOf(90, 0, 0);
  p->setTransparency(0.25);
  addObject(p);
}

void JailWindow::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
	objects->at(1)->disable();
	objects->at(2)->setQuality(3);
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(5);
	objects->at(1)->setQuality(5);
	objects->at(2)->setQuality(8);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
	objects->at(2)->enable();
  }
}
