#include "SimpleChimney.hpp"
#include <HappyTriangle.hpp>
#include <Box.hpp>

SimpleChimney::SimpleChimney()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleChimney::setBuiltIn()
{
  bv = new AABB(height, width, width);
  float h = (width-0.1)*tan(15*M_PI/180);
  Box* b1 = new Box(height-0.2-h, width-0.1, width-0.1);
  b1->translateOf(0.05, 0.05, h);
  addObject(b1);
  Box* b2 = new Box(0.2, width, width);
  b2->translateOf(0, 0, height-0.2);
  addObject(b2);
  HappyTriangle* ht = new HappyTriangle(width-0.1, width-0.1, h, 90);
  ht->rotateOf(-90, 0, 0);
  ht->translateOf(0.05, 0.05, h);
  addObject(ht);
}
