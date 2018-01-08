#include "BasicFrameDoor.hpp"

BasicFrameDoor::BasicFrameDoor()
{
  style = CLASSIC;
}

void BasicFrameDoor::setBuiltIn()
{
  float depth = 0.1;
  bv = new AABB(height, width*2+space, depth);
  Box* b1 = new Box(height, width, depth);
  Box* b2 = new Box(height, width, depth);
  Box* b3 = new Box(width, space, depth); 
  b2->translateOf(space+width, 0, 0);
  b3->translateOf(width, 0, height-width);
  addObject(b1);
  addObject(b2);
  addObject(b3);
}

void BasicFrameDoor::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
	objects->at(1)->disable();
	objects->at(2)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(3);
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
