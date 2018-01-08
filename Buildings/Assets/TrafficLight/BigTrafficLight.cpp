#include "BigTrafficLight.hpp"

BigTrafficLight::BigTrafficLight()
{
  style = CLASSIC; // a titre d'exemple
}

void BigTrafficLight::setBuiltIn()
{
  float global_width = 4;
  height = 5;
  bv = new AABB(height, global_width, 0.1+width*2-0.2*width);
  Box* b = new Box(1, width, width);
  b->translateOf(global_width-width, 0.1, 2);
  Box* b1 = new Box(height*0.95-width*0.6, width*0.6, width*0.6);
  b1->translateOf(global_width-width*0.8, width+0.1, 0);
  HappyTriangle* ht1 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht1->rotateOf(0, -90, 180);
  ht1->translateOf(global_width-width+width*0.9, 0.1, 2.9);
  HappyTriangle* ht2 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht2->rotateOf(0, -90, 180);
  ht2->translateOf(global_width-width+width*0.9, 0.1, 2.65);
  HappyTriangle* ht3 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht3->rotateOf(0, -90, 180);
  ht3->translateOf(global_width-width+width*0.9, 0.1, 2.4);
  
  Box* b2 = new Box(1, width, width);
  b2->translateOf(0, 0.1+width-width*0.2, height-1);
  HappyTriangle* ht4 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht4->rotateOf(0, -90, 180);
  ht4->translateOf(width*0.9, 0.1+width, height-0.1);
  HappyTriangle* ht5 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht5->rotateOf(0, -90, 180);
  ht5->translateOf(width*0.9, 0.1+width, height-0.35);
  HappyTriangle* ht6 = new HappyTriangle(width*0.8, 0.05, 0.1, 90);
  ht6->rotateOf(0, -90, 180);
  ht6->translateOf(width*0.9, 0.1+width, height-0.6);
  
  Box* b3 = new Box(width*0.6, global_width-width*0.2-width, width*0.6);
  b3->translateOf(width, 0.1+width, height*0.95-width*0.6);
  addObject(b);
  addObject(b1);
  addObject(ht1);
  addObject(ht2);
  addObject(ht3);
  addObject(b2);
  addObject(ht4);
  addObject(ht5);
  addObject(ht6);
  addObject(b3);
  translateOf(0, global_width, 0);
}
