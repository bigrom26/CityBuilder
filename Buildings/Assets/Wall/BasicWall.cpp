#include "BasicWall.hpp"

BasicWall::BasicWall()
{
  style = CLASSIC; // a titre d'exemple
}

void BasicWall::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  
  Box* b = new Box(height, width, depth);
  addObject(b);
}

void BasicWall::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
  }
}
