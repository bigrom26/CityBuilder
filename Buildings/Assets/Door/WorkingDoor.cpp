#include "WorkingDoor.hpp"

WorkingDoor::WorkingDoor()
{
  style = CLASSIC;
}

void WorkingDoor::setBuiltIn()
{
  float depth = 0.15;
  bv = new AABB(height, width, depth+0.1);
  Box* b_door = new Box(height, width, depth);
  Box* b1_handle = new Box(0.1*height+0.5, 0.05, 0.02);
  Box* b2_handle = new Box(0.05, 0.02, 0.08);
  Box* b3_handle = new Box(0.05, 0.02, 0.08);
  b_door->translateOf(0, 0.1, 0);
  b1_handle->translateOf(width/2+0.08, 0, 0.3*height-0.05);
  b2_handle->translateOf(width/2+0.1, 0.02, 0.3*height);
  b3_handle->translateOf(width/2+0.1, 0.02, 0.4*height+0.3);
  addObject(b_door);
  addObject(b1_handle);
  addObject(b2_handle);
  addObject(b3_handle);
  
  Box* b1_handle2 = new Box(0.1*height+0.5, 0.05, 0.02);
  Box* b2_handle2 = new Box(0.05, 0.02, 0.08);
  Box* b3_handle2 = new Box(0.05, 0.02, 0.08);
  b1_handle2->translateOf(width/2-0.11, 0, 0.3*height-0.05);
  b2_handle2->translateOf(width/2-0.1, 0.02, 0.3*height);
  b3_handle2->translateOf(width/2-0.1, 0.02, 0.4*height+0.3);
  addObject(b1_handle2);
  addObject(b2_handle2);
  addObject(b3_handle2);
}

void WorkingDoor::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
	objects->at(1)->disable();
	objects->at(2)->disable();
	objects->at(3)->disable();
	objects->at(4)->disable();
	objects->at(5)->disable();
	objects->at(6)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
	objects->at(1)->setQuality(3);
	objects->at(2)->setQuality(3);
	objects->at(3)->setQuality(3);
	objects->at(4)->setQuality(3);
	objects->at(5)->setQuality(3);
	objects->at(6)->setQuality(3);
	
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
  }
}
