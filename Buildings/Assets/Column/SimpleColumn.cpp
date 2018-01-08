#include "SimpleColumn.hpp"

SimpleColumn::SimpleColumn()
{
  style = CLASSIC;
}

void SimpleColumn::setBuiltIn()
{
  bv = new AABB(height, width, width);
  Box* b1 = new Box(height*0.05, width, width);
  Box* b2 = new Box(height*0.05, width, width);
  float radius = width/2*0.85;
  Cylinder* c = new Cylinder(radius, height-2*(height*0.05));
  b2->translateOf(0, 0, height-(height*0.05));
  c->translateOf(width/2, width/2, height*0.05);
  addObject(b1);
  addObject(b2);
  addObject(c);
}

void SimpleColumn::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
    objects->at(1)->disable();
	objects->at(2)->disable();
  }
  else if(q == MEDIUM)
  {
    objects->at(0)->disable();
    objects->at(1)->disable();
	objects->at(2)->setQuality(5);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
	objects->at(2)->enable();
  }
}
