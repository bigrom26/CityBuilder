#include "SimpleBusStop.hpp"

SimpleBusStop::SimpleBusStop()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleBusStop::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  
  Cylinder* c1 = new Cylinder(0.05, 0.3);
  c1->translateOf(0, depth/4+depth*0.2, 0);
  addObject(c1);
  Cylinder* c2 = new Cylinder(0.05, 0.3);
  c2->translateOf(0, depth*3/4+depth*0.2, 0);
  addObject(c2);
  Cylinder* c3 = new Cylinder(0.05, 0.3);
  c3->translateOf(0, depth/4+depth*0.2, height-0.4);
  addObject(c3);
  Cylinder* c4 = new Cylinder(0.05, 0.3);
  c4->translateOf(0, depth*3/4+depth*0.2, height-0.4);
  addObject(c4);
  Box* b1 = new Box(height-0.7, 0.1, depth*0.8);
  b1->translateOf(0, depth*0.2, 0.3);
  addObject(b1);
  
  Cylinder* c5 = new Cylinder(0.05, 0.3);
  c5->translateOf(width-0.1, depth/4+depth*0.2, 0);
  addObject(c5);
  Cylinder* c6 = new Cylinder(0.05, 0.3);
  c6->translateOf(width-0.1, depth*3/4+depth*0.2, 0);
  addObject(c6);
  Cylinder* c7 = new Cylinder(0.05, 0.3);
  c7->translateOf(width-0.1, depth/4+depth*0.2, height-0.4);
  addObject(c7);
  Cylinder* c8 = new Cylinder(0.05, 0.3);
  c8->translateOf(width-0.1, depth*3/4+depth*0.2, height-0.4);
  addObject(c8);
  Box* b2 = new Box(height-0.7, 0.1, depth*0.8);
  b2->translateOf(width-0.1, depth*0.2, 0.3);
  addObject(b2);
  
  Cylinder* c9 = new Cylinder(0.05, 0.3);
  c9->translateOf(width/4, depth-0.1, 0);
  addObject(c9);
  Cylinder* c10 = new Cylinder(0.05, 0.3);
  c10->translateOf(width*3/4, depth-0.1, 0);
  addObject(c10);
  Cylinder* c11 = new Cylinder(0.05, 0.3);
  c11->translateOf(width/4, depth-0.1, height-0.4);
  addObject(c11);
  Cylinder* c12 = new Cylinder(0.05, 0.3);
  c12->translateOf(width*3/4, depth-0.1, height-0.4);
  addObject(c12);
  Box* b3 = new Box(height-0.7, width-0.2, 0.1);
  b3->translateOf(0.1, depth-0.1, 0.3);
  addObject(b3);
  
  Box* b4 = new Box(0.1, width, depth);
  b4->translateOf(0, 0, height-0.1);
  addObject(b4);
  
  Box* b5 = new Box(0.1, width/2, 0.3);
  b5->translateOf(width/4, depth-0.4, 0.5);
  addObject(b5);
}
