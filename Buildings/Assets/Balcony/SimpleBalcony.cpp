#include <Architect.hpp>
#include "SimpleBalcony.hpp"

SimpleBalcony::SimpleBalcony()
{
  style = CLASSIC; // a titre d'exemple
}

void SimpleBalcony::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  //depth_guard = 0.25;
  
  if (depth > 0.2)
  {
    Box* b = new Box(0.3, width, depth);
    addObject(b);
  
    Guardrail* g1 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
	g1->set(width, height-0.3, 0.25);
    g1->translateOf(0, 0, 0.3);
	addAsset(g1);
  
	Guardrail* g2 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
	g2->set(depth-0.25, height-0.3, 0.25);
	g2->rotateOf(0, 0, -90);
	g2->translateOf(0, depth, 0.3);
	addAsset(g2);
  
	Guardrail* g3 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
	g3->set(depth-0.25, height-0.3, 0.25);
	g3->rotateOf(0, 0, -90);
	g3->translateOf(width-0.25, depth, 0.3);
	addAsset(g3);  
  }
}
