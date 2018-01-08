#include "SimpleSatelliteDish.hpp"
#include <Box.hpp>

SimpleSatelliteDish::SimpleSatelliteDish()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleSatelliteDish::setBuiltIn()
{
  float depth = 0.5;
  bv = new AABB(height, width, depth);
  
  Box* b1 = new Box(height, 0.05, 0.05);
  b1->translateOf(width/2-0.025, depth-0.05, 0);
  addObject(b1);
  
  Box* b2 = new Box(0.5/cos(30*M_PI/180), 0.05, 0.05);
  b2->translateOf(width/2-0.025, depth-0.05, height*0.2);
  b2->rotateOf(60, 0, 0);
  addObject(b2);
  
  Cylinder* c = new Cylinder(width/2, 0.025);
  c->rotateOf(60, 0, 0);
  c->translateOf(width/2, depth*0.7, height*0.5);
  addObject(c);
}

void SimpleSatelliteDish::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->disable();
    objects->at(1)->disable();
    objects->at(2)->disable();
  }
  else if(q == MEDIUM)
  {
    objects->at(0)->enable();
    objects->at(1)->disable();
    objects->at(2)->enable();
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
    objects->at(1)->enable();
    objects->at(2)->enable();
  }
}
