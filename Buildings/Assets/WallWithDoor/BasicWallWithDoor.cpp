#include <Architect.hpp>
#include "BasicWallWithDoor.hpp"

BasicWallWithDoor::BasicWallWithDoor()
{
  style = CLASSIC; // a titre d'exemple
}

/* Pas encore fini, juste un test pour commencer ! */
void BasicWallWithDoor::setBuiltIn()
{
  float depth = 0.3;
  bv = new AABB(height, width, depth+0.1);
 
  FrameDoor* f = dynamic_cast<FrameDoor*>(archi->get("G_FRAMEDOOR"));
  f->set();
  f->translateOf(width/2-0.5-0.1, 0, 0);
  addAsset(f);
  
  Door* d = dynamic_cast<Door*>(archi->get("G_DOOR"));
  d->set();
  d->translateOf(width/2-0.5, 0.0875, 0);
  addAsset(d);
  
  WallWithWindow* w1 = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w1->set(width/2-0.5, height);
  addAsset(w1);
  
  WallWithWindow* w2 = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w2->set(width/2-0.5, height);
  w2->translateOf(width/2+0.5, 0, 0);
  addAsset(w2);
  
  Box* topBox = new Box(height-2, 1, depth);
  topBox->translateOf(width/2-0.5, 0.1, 2);
  addObject(topBox);
}

void BasicWallWithDoor::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
  }
}
