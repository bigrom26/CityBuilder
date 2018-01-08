#include "Bar.hpp"

Bar::Bar()
{
  style = CLASSIC; // a titre d'exemple
}

void Bar::setBuiltIn()
{
  float depth = 0.1;
  bv = new AABB(height, width, depth);
  
  Box* b1 = new Box(height, width, depth);
  addObject(b1);
}

void Bar::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(3);
	
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
  }
}
