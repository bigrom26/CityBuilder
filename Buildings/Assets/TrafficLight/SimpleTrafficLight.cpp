#include "SimpleTrafficLight.hpp"

SimpleTrafficLight::SimpleTrafficLight()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleTrafficLight::setBuiltIn()
{
  bv = new AABB(height, width, width+0.1);
  Box* b = new Box(height*1/3, width, width);
  b->translateOf(0, 0.1, height*2/3);
  Cylinder* c = new Cylinder(width*0.3, height*2/3);
  c->translateOf(width/2, 0.1+width/2, 0);
  HappyTriangle* ht1 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht1->rotateOf(0, -90, 180);
  ht1->translateOf(width*0.9, 0.1, height-(0.1*1/3*height));
  HappyTriangle* ht2 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht2->rotateOf(0, -90, 180);
  ht2->translateOf(width*0.9, 0.1, height-(0.35*1/3*height));
  HappyTriangle* ht3 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht3->rotateOf(0, -90, 180);
  ht3->translateOf(width*0.9, 0.1, height-(0.60*1/3*height));
  addObject(b);
  addObject(c);
  addObject(ht1);
  addObject(ht2);
  addObject(ht3);
}
