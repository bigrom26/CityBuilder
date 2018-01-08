#include "FrameDoorWithTriangle.hpp"

FrameDoorWithTriangle::FrameDoorWithTriangle()
{
  style = CLASSIC;
}

void FrameDoorWithTriangle::setBuiltIn()
{
  BasicFrameDoor::setBuiltIn();
  float depth = 0.1;
  bv = new AABB(height+width+space/4, width*2+space, depth);
  HappyTriangle* ht = new HappyTriangle(depth, space/2, space/4, 45);
  ht->translateOf(width+space/4, depth, height+width);
  ht->rotateOf(90, 0, 0);
  addObject(ht);
}

void FrameDoorWithTriangle::_changeQuality(QUALITY q)
{
  BasicFrameDoor::_changeQuality(q);
  if(q == LOW)
  {
    objects->at(3)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(3)->setQuality(3);
	
  }
  else if(q == HIGHT)
  {
    objects->at(3)->enable();
  }
}