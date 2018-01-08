#include <Architect.hpp>
#include "SkyscraperBuilding.hpp"

SkyscraperBuilding::SkyscraperBuilding()
{
  style = CLASSIC;
}

void SkyscraperBuilding::setBuiltIn()
{
  bv = new AABB((nbLevel/3*3*3)+3+(nbLevel*3+6)*0.15, width, depth);
  
  BottomFloor* bf = dynamic_cast<BottomFloor*>(archi->get("G_BOTTOMFLOOR"));
  bf->set(width, 3, depth);
  addAsset(bf);
  
  for (float i=0; i<(nbLevel*1/3); i++)
  {
    MiddleFloor* mf = dynamic_cast<MiddleFloor*>(archi->get("G_MIDDLEFLOOR"));
    mf->set(width, 3, depth);
    mf->translateOf(0, 0, i*3+3);
    addAsset(mf);
  }
  
  Guardrail* g1 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g1->set(width-0.2);
  g1->translateOf(0.1, 0.1, 3+(nbLevel*1/3)*3);
  addAsset(g1);
  Guardrail* g2 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g2->set(depth-0.4);
  g2->rotateOf(0, 0, 90);
  g2->translateOf(0.2, 0.2, 3+(nbLevel*1/3)*3);
  addAsset(g2);
  Guardrail* g3 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g3->set(depth-0.4);
  g3->rotateOf(0, 0, 90);
  g3->translateOf(width-0.1, 0.1, 3+(nbLevel*1/3)*3);
  addAsset(g3);
  Guardrail* g4 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g4->set(width-0.2);
  g4->translateOf(0.1, depth-0.1, 3+(nbLevel*1/3)*3);
  addAsset(g4);
  
  for (float i=0; i<(nbLevel*1/3); i++)
  {
    MiddleFloor* mf = dynamic_cast<MiddleFloor*>(archi->get("G_MIDDLEFLOOR"));
    mf->set(width*0.7, 3, depth*0.7);
    mf->translateOf(width*0.15, depth*0.15, 3+(nbLevel*1/3)*3+i*3);
    addAsset(mf);
  }
  
  if (nbLevel % 3 != 0)
  {
    MiddleFloor* mf = dynamic_cast<MiddleFloor*>(archi->get("G_MIDDLEFLOOR"));
    mf->set(width*0.7, 3, depth*0.7);
    mf->translateOf(width*0.15, depth*0.15, (nbLevel*2/3)*3);
    addAsset(mf);
  }
  
  Guardrail* g5 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g5->set(width*0.7-0.2);
  g5->translateOf(width*0.15+0.1, width*0.15+0.1, 3+(nbLevel*2/3)*3);
  addAsset(g5);
  Guardrail* g6 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g6->set(depth*0.7-0.4);
  g6->rotateOf(0, 0, 90);
  g6->translateOf(width*0.15+0.2, depth*0.15+0.2, 3+(nbLevel*2/3)*3);
  addAsset(g6);
  Guardrail* g7 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g7->set(depth*0.7-0.4);
  g7->rotateOf(0, 0, 90);
  g7->translateOf(width*0.85-0.1, depth*0.15+0.1, 3+(nbLevel*2/3)*3);
  addAsset(g7);
  Guardrail* g8 = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g8->set(width*0.7-0.2);
  g8->translateOf(width*0.15+0.1, depth*0.85-0.2, 3+(nbLevel*2/3)*3);
  addAsset(g8);
  
  for (float i=0; i<(nbLevel*1/3-1); i++)
  {
    MiddleFloor* mf = dynamic_cast<MiddleFloor*>(archi->get("G_MIDDLEFLOOR"));
    mf->set(width*0.4, 3, depth*0.4);
    mf->translateOf(width*0.3, depth*0.3, 3+(nbLevel*2/3)*3+i*3);
    addAsset(mf);
  }
  
  TopFloor* tf = dynamic_cast<TopFloor*>(archi->get("G_TOPFLOOR"));
  tf->set(width*0.4+0.4, 3, depth*0.4+0.4);
  tf->translateOf(width*0.3-0.2, depth*0.3-0.2, (nbLevel/3*3*3));
  addAsset(tf);
  
  Cylinder* c = new Cylinder(0.05, (nbLevel*3+6)*0.15);
  c->translateOf(width/2, depth/2, (nbLevel/3*3*3)+3);
  addObject(c);
  
  SatelliteDish* sd = dynamic_cast<SatelliteDish*>(archi->get("G_SATELLITEDISH"));
  sd->set(width*0.1, nbLevel*3*0.1);
  sd->rotateOf(0, 0, -45);
  sd->translateOf(width/2-width*0.1, depth/2-depth*0.1, (nbLevel/3*3*3)+3);
  addAsset(sd);
}
