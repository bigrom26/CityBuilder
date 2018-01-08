#include "DoorWithHole.hpp"
#include <Plane.hpp>

DoorWithHole::DoorWithHole()
{
  style = CLASSIC;
}

void DoorWithHole::setBuiltIn()
{
  float depth = 0.15;
  bv = new AABB(height, width, depth+0.1);
  Box* b = new Box(0.3, 0.1, 0.01);
  Box* b_door = new Box(height-0.1*height-0.3, width, depth);
  Box* b_door2 = new Box(0.3, (width-0.6)/2, depth);
  Box* b_door3 = new Box(0.3, (width-0.6)/2, depth);
  Box* b_door4 = new Box(0.1*height, width, depth);
  Box* b1_handle = new Box(0.05, 0.2, 0.02);
  Box* b2_handle = new Box(0.05, 0.02, 0.09);
  b->translateOf(0.05, 0.09, 0.4*height-0.18);
  b_door->translateOf(0, 0.1, 0);
  b_door2->translateOf(0, 0.1, height-0.1*height-0.3);
  b_door3->translateOf((width-0.6)/2+0.6, 0.1, height-0.1*height-0.3);
  b_door4->translateOf(0, 0.1, height-0.1*height);
  b1_handle->translateOf(0.12, 0, 0.4*height);
  b2_handle->translateOf(0.1, 0, 0.4*height);
  Plane* p = new Plane(width, height, true);
  p->translateOf(0, 0.17, 0);
  p->rotateOf(90, 0, 0);
  p->setTransparency(0.25);
  addObject(p);
  addObject(b);
  addObject(b_door);
  addObject(b_door2);
  addObject(b_door3);
  addObject(b_door4);
  addObject(b1_handle);
  addObject(b2_handle);
}

void DoorWithHole::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
	objects->at(1)->disable();
	objects->at(2)->setQuality(3);
	objects->at(3)->setQuality(3);
	objects->at(4)->setQuality(3);
	objects->at(5)->setQuality(3);
	objects->at(6)->disable();
	objects->at(7)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
	objects->at(1)->setQuality(3);
	objects->at(2)->setQuality(8);
	objects->at(3)->setQuality(8);
	objects->at(4)->setQuality(8);
	objects->at(5)->setQuality(8);
	objects->at(6)->setQuality(3);
	objects->at(7)->setQuality(3);
	
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
	objects->at(2)->enable();
	objects->at(3)->enable();
	objects->at(4)->enable();
	objects->at(5)->enable();
	objects->at(6)->enable();
	objects->at(7)->enable();
  }
}
