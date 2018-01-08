#include <Architect.hpp>
#include "BottomFloorWithTwoFacades.hpp"

BottomFloorWithTwoFacades::BottomFloorWithTwoFacades()
{
  style = CLASSIC; // a titre d'exemple
}

void BottomFloorWithTwoFacades::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  Box* ceiling = new Box(0.3, width-(2*0.4), depth-(2*0.4));
  ceiling->translateOf(0.4, 0.4, height-0.3);
  addObject(ceiling);
   
  WallWithDoor* w_front = dynamic_cast<WallWithDoor*>(archi->get("G_WALLWITHDOOR"));
  w_front->set(width-0.2, height);
  w_front->translateOf(0.1, 0, 0);
  addAsset(w_front);
    
  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(depth, 0.2);
  d1->rotateOf(0, 0, -90);
  d1->translateOf(0, depth, height/3);
  addAsset(d1);
  
  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(depth, 0.2);
  d2->rotateOf(0, 0, -90);
  d2->translateOf(0, depth, height*2/3);
  addAsset(d2);
  
  Wall* w_left = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_left->set(depth-0.8, height);
  w_left->rotateOf(0, 0, -90);
  w_left->translateOf(0.1, depth-0.4, 0);
  addAsset(w_left);
  
  Decoration* d3 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d3->set(depth, 0.2);
  d3->rotateOf(0, 0, 90);
  d3->translateOf(width, 0, height/3);
  addAsset(d3);
  
  Decoration* d4 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d4->set(depth, 0.2);
  d4->rotateOf(0, 0, 90);
  d4->translateOf(width, 0, height*2/3);
  addAsset(d4);
  
  Wall* w_right = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_right->set(depth-0.8, height);
  w_right->rotateOf(0, 0, 90);
  w_right->translateOf(width-0.1, 0.4, 0);
  addAsset(w_right);
  
  WallWithWindow* w_back = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_back->set(width-0.2, height);
  w_back->rotateOf(0, 0, 180);
  w_back->translateOf(width-0.1, depth, 0);
  addAsset(w_back);
}
