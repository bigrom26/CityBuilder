#include <Architect.hpp>
#include "BasicWallWithWindow.hpp"

BasicWallWithWindow::BasicWallWithWindow()
{
  style = CLASSIC; // a titre d'exemple
}

/* Pas encore fini, juste un test pour commencer ! */
void BasicWallWithWindow::setBuiltIn()
{
  int nbWin = (int)width/2.5;
  float depth = 0.3;
  float space = (width-nbWin*1)/(nbWin+1);
  bv = new AABB(height, width, depth+0.1);
  for (int i=0; i<nbWin; i++)
  {
    FrameWindow* f = dynamic_cast<FrameWindow*>(archi->get("G_FRAMEWINDOW"));
    f->set();
    f->translateOf(i*space+i+space-0.1, 0, height-1.5-height/6-0.1);
    addAsset(f);
	
    Window* w = dynamic_cast<Window*>(archi->get("G_WINDOW"));
    w->set();
    w->translateOf(i*space+i+space, depth/2, height-1.5-height/6);
    addAsset(w);
	
    Wall* w_left = dynamic_cast<Wall*>(archi->get("G_WALL"));
    w_left->set(space, 1.5, depth);
    w_left->translateOf(i*space+i, 0.1, height-1.5-height/6);
    addAsset(w_left);
	
    Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d1->set(space, 0.2);
    d1->translateOf(i*space+i, 0, height/3);
    addAsset(d1);
	
    Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d2->set(space, 0.2);
    d2->translateOf(i*space+i, 0, height*2/3);
    addAsset(d2);
  }
  /*Wall* w_bottom = dynamic_cast<Wall*>(archi->get(WALL));
  w_bottom->set(height-1.5-height/6, width, depth);
  w_bottom->translateOf(0, 0.1, 0);
  addAsset(w_bottom);
  Wall* w_top = dynamic_cast<Wall*>(archi->get(WALL));
  w_top->set(height/6, width, depth);
  w_top->translateOf(0, 0.1, height-height/6);
  addAsset(w_top);*/
  Wall* w_right = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_right->set(space, 1.5, depth);
  w_right->translateOf(width-space, 0.1, height-1.5-height/6);
  addAsset(w_right);
  
  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(space, 0.2);
  d1->translateOf(width-space, 0, height/3);
  addAsset(d1);
	
  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(space, 0.2);
  d2->translateOf(width-space, 0, height*2/3);
  addAsset(d2);
  
  Box* bottomBox = new Box(height-1.5-height/6, width, depth);
  bottomBox->translateOf(0, 0.1, 0);
  addObject(bottomBox);
  
  Box* topBox = new Box(height/6, width, depth);
  topBox->translateOf(0, 0.1, height-height/6);
  addObject(topBox);
  
 /* Box* rightBox = new Box(1.5, space, depth);
  rightBox->translateOf(width-space, 0.1, height-1.5-height/6); 
  addObject(rightBox);*/
 
}

void BasicWallWithWindow::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
	objects->at(1)->setQuality(3);
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
	objects->at(1)->setQuality(3);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
  }
}
