#include "SimpleStreetlight.hpp"

SimpleStreetlight::SimpleStreetlight()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleStreetlight::setBuiltIn()
{
  bv = new AABB(height, width, width);
  Cylinder* c = new Cylinder(width/6, height*0.8);
  c->translateOf(width/2, width/2, 0);
  HappyCylinder* hc = new HappyCylinder(width/4, width/2, height*0.2);
  hc->translateOf(width/2, width/2, height*0.8);
  addObject(hc);
  addObject(c);
}

void SimpleStreetlight::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
    objects->at(1)->setQuality(4);
  }
  else if(q == MEDIUM)
  {
    objects->at(0)->setQuality(6);
    objects->at(1)->setQuality(6);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
    objects->at(1)->setQuality(20);
  }
}
