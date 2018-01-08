#include <Architect.hpp>
#include "WallWithBigWindow.hpp"

WallWithBigWindow::WallWithBigWindow()
{
  style = CLASSIC; // a titre d'exemple
}

/* Pas encore fini, juste un test pour commencer ! */
void WallWithBigWindow::setBuiltIn()
{
  int nbWin = (int)width/2.5;
  float depth = 0.3;
  float space = (width-nbWin*2)/(nbWin+1);
  bv = new AABB(height, width, depth+0.1);
  
  for (int i=0; i<nbWin; i++)
  {
    FrameDoor* f = dynamic_cast<FrameDoor*>(archi->get("G_FRAMEDOOR"));
    f->set(0.1, 2, 2);
    f->translateOf(i*space+i*2+space-0.1, 0, 0);
    addAsset(f);
	
    Window* w = dynamic_cast<Window*>(archi->get("G_WINDOW"));
    w->set(2, 2);
    w->translateOf(i*space+i*2+space, depth/2, 0);
    addAsset(w);
	
    Wall* w_left = dynamic_cast<Wall*>(archi->get("G_WALL"));
    w_left->set(space, 2, depth);
    w_left->translateOf(i*space+i*2, 0.1, 0);
    addAsset(w_left);
	
    Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d1->set(space, 0.2);
    d1->translateOf(i*space+i*2, 0, height/3);
    addAsset(d1);
	
    Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d2->set(space, 0.2);
    d2->translateOf(i*space+i*2, 0, height*2/3);
    addAsset(d2);
  }
  
  Wall* w_right = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_right->set(space, 2, depth);
  w_right->translateOf(width-space, 0.1, 0);
  addAsset(w_right);
  
  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(space, 0.2);
  d1->translateOf(width-space, 0, height/3);
  addAsset(d1);
	
  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(space, 0.2);
  d2->translateOf(width-space, 0, height*2/3);
  addAsset(d2);
  
  Box* topBox = new Box(height-2, width, depth);
  topBox->translateOf(0, 0.1, 2);
  addObject(topBox); 
}

void WallWithBigWindow::_changeQuality(QUALITY q)
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
