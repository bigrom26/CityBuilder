#include <Architect.hpp>
#include "FactoryTopFloor.hpp"

FactoryTopFloor::FactoryTopFloor()
{
  style = CLASSIC; // a titre d'exemple
}

void FactoryTopFloor::setBuiltIn()
{
  Roof* r = dynamic_cast<Roof*>(archi->get("G_ROOF"));
  r->set(width, depth);
  r->translateOf(0, 0, height);
  addAsset(r);
  float global_height = r->getHeight() + height;

  bv = new AABB(global_height, width, depth);

  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(0.4, 0.2);
  d1->rotateOf(0, 0, -90);
  d1->translateOf(0.2, depth-0.2, height/3);
  addAsset(d1);

  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(0.4, 0.2);
  d2->rotateOf(0, 0, -90);
  d2->translateOf(0.2, depth-0.2, height*2/3);
  addAsset(d2);

  Decoration* d3 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d3->set(0.4, 0.2);
  d3->rotateOf(0, 0, -90);
  d3->translateOf(0.2, 0.6, height/3);
  addAsset(d3);

  Decoration* d4 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d4->set(0.4, 0.2);
  d4->rotateOf(0, 0, -90);
  d4->translateOf(0.2, 0.6, height*2/3);
  addAsset(d4);

  Decoration* d5 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d5->set(0.4, 0.2);
  d5->rotateOf(0, 0, -90);
  d5->translateOf(width-0.3, depth-0.2, height/3);
  addAsset(d5);

  Decoration* d6 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d6->set(0.4, 0.2);
  d6->rotateOf(0, 0, -90);
  d6->translateOf(width-0.3, depth-0.2, height*2/3);
  addAsset(d6);

  Decoration* d7 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d7->set(0.4, 0.2);
  d7->rotateOf(0, 0, -90);
  d7->translateOf(width-0.3, 0.6, height/3);
  addAsset(d7);

  Decoration* d8 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d8->set(0.4, 0.2);
  d8->rotateOf(0, 0, -90);
  d8->translateOf(width-0.3, 0.6, height*2/3);
  addAsset(d8);

  WallWithWindow* w_front = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_front->set(width-0.6, height);
  w_front->translateOf(0.3, 0.2, 0);
  addAsset(w_front);

  WallWithWindow* w_left = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_left->set(depth-1.2, height);
  w_left->rotateOf(0, 0, -90);
  w_left->translateOf(0.2, depth-0.6, 0);
  addAsset(w_left);

  WallWithWindow* w_right = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_right->set(depth-1.2, height);
  w_right->rotateOf(0, 0, 90);
  w_right->translateOf(width-0.2, 0.6, 0);
  addAsset(w_right);

  WallWithWindow* w_back = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_back->set(width-0.6, height);
  w_back->rotateOf(0, 0, 180);
  w_back->translateOf(width-0.3, depth-0.2, 0);
  addAsset(w_back);
}
