#include <Architect.hpp>
#include "CommercialBottomFloor.hpp"

CommercialBottomFloor::CommercialBottomFloor()
{
  style = CLASSIC; // a titre d'exemple
}

void CommercialBottomFloor::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  Box* ceiling = new Box(0.3, width, depth);
  ceiling->translateOf(0, 0, height-0.3);
  addObject(ceiling);
  
  int nb_col = (int)width/3;
  float rest = (width-3*(int)(width/3))/(nb_col-1);
  
  Column* c1 = dynamic_cast<Column*>(archi->get("G_COLUMN"));
  c1->set(0.5, height-0.3);
  addAsset(c1);
  Column* c2 = dynamic_cast<Column*>(archi->get("G_COLUMN"));
  c2->set(0.5, height-0.3);
  c2->translateOf(0, depth-0.5, 0);
  addAsset(c2);
  
  for (int i=1; i<=nb_col; i++)
  {
    Column* c3 = dynamic_cast<Column*>(archi->get("G_COLUMN"));
    c3->set(0.5, height-0.3);
    c3->translateOf(i*3+rest, 0, 0);
    addAsset(c3);
    Column* c4 = dynamic_cast<Column*>(archi->get("G_COLUMN"));
    c4->set(0.5, height-0.3);
    c4->translateOf(i*3+rest, depth-0.5, 0);
    addAsset(c4);
  }
  
  nb_col = (int)depth/3;
  rest = (depth-3*(int)(depth/3))/(nb_col-1);
  
  for (int i=1; i<nb_col; i++)
  {
    Column* c3 = dynamic_cast<Column*>(archi->get("G_COLUMN"));
    c3->set(0.5, height-0.3);
    c3->translateOf(0, i*3+rest, 0);
    addAsset(c3);
    Column* c4 = dynamic_cast<Column*>(archi->get("G_COLUMN"));
    c4->set(0.5, height-0.3);
    c4->translateOf(width-0.5, i*3+rest, 0);
    addAsset(c4);
  }
   
  WallWithDoor* w_front = dynamic_cast<WallWithDoor*>(archi->get("G_WALLWITHDOOR"));
  w_front->set(width-4.2, height-0.3);
  w_front->translateOf(2.1, 2.1, 0);
  addAsset(w_front);
  
  WallWithDoor* w_back = dynamic_cast<WallWithDoor*>(archi->get("G_WALLWITHDOOR"));
  w_back->set(width-4.2, height-0.3);
  w_back->rotateOf(0, 0, 180);
  w_back->translateOf(width-2.1, depth-2.1, 0);
  addAsset(w_back);
  
  WallWithWindow* w_left = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_left->set(depth-5, height-0.3);
  w_left->rotateOf(0, 0, -90);
  w_left->translateOf(2, depth-2.5, 0);
  addAsset(w_left);
  
  WallWithWindow* w_right = dynamic_cast<WallWithWindow*>(archi->get("G_WALLWITHWINDOW"));
  w_right->set(depth-5, height-0.3);
  w_right->rotateOf(0, 0, 90);
  w_right->translateOf(width-2, 2.5, 0);
  addAsset(w_right);
  
  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(0.4, 0.2);
  d1->rotateOf(0, 0, -90);
  d1->translateOf(2, depth-2.1, (height-0.3)/3);
  addAsset(d1);
  
  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(0.4, 0.2);
  d2->rotateOf(0, 0, -90);
  d2->translateOf(2, depth-2.1, (height-0.3)*2/3);
  addAsset(d2);
  
  Decoration* d3 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d3->set(0.4, 0.2);
  d3->rotateOf(0, 0, -90);
  d3->translateOf(2, 2.5, (height-0.3)/3);
  addAsset(d3);
  
  Decoration* d4 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d4->set(0.4, 0.2);
  d4->rotateOf(0, 0, -90);
  d4->translateOf(2, 2.5, (height-0.3)*2/3);
  addAsset(d4);
  
  Decoration* d5 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d5->set(0.4, 0.2);
  d5->rotateOf(0, 0, -90);
  d5->translateOf(width-2.1, depth-2.1, (height-0.3)/3);
  addAsset(d5);
  
  Decoration* d6 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d6->set(0.4, 0.2);
  d6->rotateOf(0, 0, -90);
  d6->translateOf(width-2.1, depth-2.1, (height-0.3)*2/3);
  addAsset(d6);
  
  Decoration* d7 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d7->set(0.4, 0.2);
  d7->rotateOf(0, 0, -90);
  d7->translateOf(width-2.1, 2.5, (height-0.3)/3);
  addAsset(d7);
  
  Decoration* d8 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d8->set(0.4, 0.2);
  d8->rotateOf(0, 0, -90);
  d8->translateOf(width-2.1, 2.5, (height-0.3)*2/3);
  addAsset(d8);
}
