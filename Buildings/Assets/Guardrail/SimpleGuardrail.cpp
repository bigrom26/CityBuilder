#include "SimpleGuardrail.hpp"

SimpleGuardrail::SimpleGuardrail()
{
  style = CLASSIC;
}

void SimpleGuardrail::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  Box* b_top = new Box(0.1, width, depth);
  b_top->translateOf(0, 0, height-0.1);
  addObject(b_top);
  for (float i = 0; i < width; i+=space)
  {
	Box* b = new Box(height-0.1, depth*0.3, depth*0.3);
	b->translateOf(i, 0.35*depth, 0);
	addObject(b);
  }
}
