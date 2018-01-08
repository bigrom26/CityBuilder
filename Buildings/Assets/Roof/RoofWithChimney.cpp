#include <Architect.hpp>
#include "RoofWithChimney.hpp"
#include "SimpleRoof.hpp"
#include <Chimney.hpp>
//#include "SatelliteDish.hpp"

RoofWithChimney::RoofWithChimney()
{
  style = CLASSIC; // a titre d'exemple
}

void RoofWithChimney::setBuiltIn()
{
  SimpleRoof::setBuiltIn();
  float height = getHeight();
  bv = new AABB(height+1, width, depth);
  
  Chimney* c = dynamic_cast<Chimney*>(archi->get("G_CHIMNEY"));
  c->set();
  c->rotateOf(0, 0, 90);
  c->translateOf(width*0.4, depth*0.2, depth*0.2*0.15);
  addAsset(c);
  
 /* SatelliteDish* s = dynamic_cast<SatelliteDish*>(archi->get("SATELLITEDISH"));
  s->set();
  s->rotateOf(0, 0, 135);
  s->translateOf(width*0.7, depth*0.8, depth*0.2*0.15-0.05);
  addAsset(s);*/
}
