#include <Architect.hpp>
#include "BasicBuilding.hpp"

BasicBuilding::BasicBuilding()
{
  style = CLASSIC;
}

void BasicBuilding::setBuiltIn()
{
  BottomFloor* bf = dynamic_cast<BottomFloor*>(archi->get("G_BOTTOMFLOOR"));
  bf->set(width-0.4, 3, depth-0.4);
  bf->translateOf(0.2, 0.2, 0);
  addAsset(bf);

  float wid2;
  float dep2;
  
  for (int i=0; i<nbLevel; i++)
  {
    MiddleFloor* mf = dynamic_cast<MiddleFloor*>(archi->get("G_MIDDLEFLOOR"));
    mf->set(width-0.4, 3, depth-0.4);
    mf->translateOf(0.2, 0.2, i*3+3);
    addAsset(mf);
    wid2 = (mf->getBV())->getX();
    dep2 = (mf->getBV())->getY();
  }
  
  TopFloor* tf = dynamic_cast<TopFloor*>(archi->get("G_TOPFLOOR"));
  tf->set(width, 3, depth);
  tf->translateOf(0, 0, (nbLevel+1)*3);
  addAsset(tf);
  
  float wid3 = (tf->getBV())->getX();
  float dep3 = (tf->getBV())->getY();
  
  float width2, depth2;
  
  /*********** INCOMPREHENSIBLE !!!!!!!!!!! VOIR BASICMIDDLEFLOOR.cpp : idem !!!! **********************/
  if (dep2 < dep3)
    depth2 = dep2;
  else
    depth2 = dep3;
  
  if (wid2 < wid3)
    width2 = wid2;
  else
    width2 = wid3;
  
  bv = new AABB((nbLevel+1)*3+3+depth/2*tan(15*M_PI/180), width-2*width2, depth-2*depth2);
  bv->translateOf(width2, depth2, 0);
}
