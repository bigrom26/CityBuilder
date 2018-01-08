#include "CrossWindow.hpp"

CrossWindow::CrossWindow()
{
  style = CLASSIC;
}

void CrossWindow::setBuiltIn()
{
  float depth = 0.05;
  bv = new AABB(height, width, depth);
  Box* b1 = new Box(height, depth, depth);
  Box* b2 = new Box(depth, width, depth);
  b1->translateOf(width/2-depth/2, 0, 0);
  b2->translateOf(0, 0, height/2-depth/2);
  addObject(b1);
  addObject(b2);
  
  Plane* p = new Plane(width, height, true);
  p->rotateOf(90, 0, 0);
  p->setTransparency(0.25);
  addObject(p);
}

void CrossWindow::_changeQuality(QUALITY q)
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
