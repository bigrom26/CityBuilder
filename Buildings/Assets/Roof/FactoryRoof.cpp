#include <Architect.hpp>
#include "FactoryRoof.hpp"
#include <Cylinder.hpp>

FactoryRoof::FactoryRoof()
{
  style = CLASSIC; // a titre d'exemple
}

void FactoryRoof::setBuiltIn()
{
  float height = 0.3;
  bv = new AABB(height+7, width, depth);
  
  Box* b = new Box(height, width-0.6, depth-0.6);
  b->translateOf(0.3, 0.3, 0);
  addObject(b);
  
  HappyTriangle* ht1 = new HappyTriangle(width-0.6, 0.3, 0.3, 90);
  ht1->rotateOf(0, 90, -90);
  ht1->translateOf(0.3, 0.3, height);
  addObject(ht1);
 
  HappyTriangle* ht2 = new HappyTriangle(width-0.6, 0.3, 0.3, 90);
  ht2->rotateOf(0, 90, 0);
  ht2->translateOf(0.3, depth-0.3, height);
  addObject(ht2);
  
  HappyTriangle* ht3 = new HappyTriangle(depth-0.6, 0.3, 0.3, 90);
  ht3->rotateOf(90, 0, 180);
  ht3->translateOf(0.3, depth-0.3, height);
  addObject(ht3);
  
  HappyTriangle* ht4 = new HappyTriangle(depth-0.6, 0.3, 0.3, 90);
  ht4->rotateOf(90, 0, -90);
  ht4->translateOf(width-0.3, depth-0.3, height);
  addObject(ht4);
  
  Cylinder* c = new Cylinder(0.8, 7);
  c->translateOf(width*0.6, depth/3, 0.3);
  addObject(c);
  
  Cylinder* c2 = new Cylinder(0.5, 3);
  c2->translateOf(width*0.3, depth*2/3, 0.3);
  addObject(c2);
}
