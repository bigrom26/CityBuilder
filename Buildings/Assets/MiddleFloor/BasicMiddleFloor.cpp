#include <Architect.hpp>
#include "BasicMiddleFloor.hpp"

BasicMiddleFloor::BasicMiddleFloor()
{
  style = CLASSIC; // a titre d'exemple
}

void BasicMiddleFloor::setBuiltIn()
{
  Box* ceiling = new Box(0.3, width-(2*0.4), depth-(2*0.4));
  ceiling->translateOf(0.4, 0.4, height-0.3);
  addObject(ceiling);
  
  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(0.4, 0.2);
  d1->rotateOf(0, 0, -90);
  d1->translateOf(0, depth, height/3);
  addAsset(d1);
  
  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(0.4, 0.2);
  d2->rotateOf(0, 0, -90);
  d2->translateOf(0, depth, height*2/3);
  addAsset(d2);
  
  Decoration* d3 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d3->set(0.4, 0.2);
  d3->rotateOf(0, 0, -90);
  d3->translateOf(0, 0.4, height/3);
  addAsset(d3);
  
  Decoration* d4 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d4->set(0.4, 0.2);
  d4->rotateOf(0, 0, -90);
  d4->translateOf(0, 0.4, height*2/3);
  addAsset(d4);
  
  Decoration* d5 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d5->set(0.4, 0.2);
  d5->rotateOf(0, 0, -90);
  d5->translateOf(width-0.1, depth, height/3);
  addAsset(d5);
  
  Decoration* d6 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d6->set(0.4, 0.2);
  d6->rotateOf(0, 0, -90);
  d6->translateOf(width-0.1, depth, height*2/3);
  addAsset(d6);
  
  Decoration* d7 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d7->set(0.4, 0.2);
  d7->rotateOf(0, 0, -90);
  d7->translateOf(width-0.1, 0.4, height/3);
  addAsset(d7);
  
  Decoration* d8 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d8->set(0.4, 0.2);
  d8->rotateOf(0, 0, -90);
  d8->translateOf(width-0.1, 0.4, height*2/3);
  addAsset(d8);
  
  WallWithWindow* w_front = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_front->set(width-0.2, height);
  w_front->translateOf(0.1, 0, 0);
  addAsset(w_front);
  float dep1 = (w_front->getBV())->getY();
  
  WallWithWindow* w_left = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_left->set(depth-0.8, height);
  w_left->rotateOf(0, 0, -90);
  w_left->translateOf(0, depth-0.4, 0);
  addAsset(w_left);
  float dep2 = (w_left->getBV())->getY();
  
  WallWithWindow* w_right = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_right->set(depth-0.8, height);
  w_right->rotateOf(0, 0, 90);
  w_right->translateOf(width, 0.4, 0);
  addAsset(w_right);
  float dep3 = (w_right->getBV())->getY();
  
  WallWithWindow* w_back = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_back->set(width-0.2, height);
  w_back->rotateOf(0, 0, 180);
  w_back->translateOf(width-0.1, depth, 0);
  addAsset(w_back);
  float dep4 = (w_back->getBV())->getY();
  
  bv = new AABB(height+0.3, width-dep2-dep3, depth-dep1-dep4);
  bv->translateOf(dep2, dep1, -0.3);  
}
