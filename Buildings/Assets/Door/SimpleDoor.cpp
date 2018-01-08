#include "SimpleDoor.hpp"

SimpleDoor::SimpleDoor()
{
  style = CLASSIC;
}

void SimpleDoor::setBuiltIn()
{
  float depth = 0.15;
  bv = new AABB(height, width, depth+0.1);
  Box* b_door = new Box(height, width, depth);
  Box* b1_handle = new Box(0.05, 0.2, 0.02);
  Box* b2_handle = new Box(0.05, 0.02, 0.1);
  b_door->translateOf(0, 0.1, 0);
  b1_handle->translateOf(0.12, 0, 0.4*height);
  b2_handle->translateOf(0.1, 0, 0.4*height);
  addObject(b_door);
  addObject(b1_handle);
  addObject(b2_handle);
}

void SimpleDoor::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
	objects->at(1)->disable();
	objects->at(2)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
	objects->at(1)->setQuality(3);
	objects->at(2)->setQuality(3);
	
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
	objects->at(2)->enable();
  }
}
