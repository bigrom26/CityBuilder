#include "SimpleRoof.hpp"

SimpleRoof::SimpleRoof()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleRoof::setBuiltIn()
{
  float height = getHeight();
  bv = new AABB(height, width, depth);
  HappyTriangle* ht1 = new HappyTriangle(width, height, depth/2, 90);
  ht1->rotateOf(0, -90, 0);
  ht1->translateOf(width, depth/2, 0);
  HappyTriangle* ht2 = new HappyTriangle(width, height, depth/2, 90);
  ht2->rotateOf(0, 90, 180);
  ht2->translateOf(0, depth/2, 0);
  addObject(ht1);
  addObject(ht2);
}
