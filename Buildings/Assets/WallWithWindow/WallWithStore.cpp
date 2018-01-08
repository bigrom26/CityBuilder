#include <Architect.hpp>
#include "WallWithStore.hpp"

WallWithStore::WallWithStore()
{
  style = CLASSIC; // a titre d'exemple
}

void WallWithStore::setBuiltIn()
{
  int nbWin = (int)width/2.5;
  float depth = 0.3;
  float space = (width-nbWin*1)/(nbWin+1);
  bv = new AABB(height, width, depth+0.1+1);
  bv->translateOf(0, -1, 0);
  
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
  
  for (int i=0; i<nbWin; i++)
  {
    FrameWindow* f = dynamic_cast<FrameWindow*>(archi->get("G_FRAMEWINDOW"));
    f->set();
    f->translateOf(i*space+i+space-0.1, 0, height-1.5-height/6-0.1);
    addAsset(f);
	
    HappyTriangle* ht = new HappyTriangle(1/(sin((180-135)*M_PI/180)), 1.5, 0.1*(sin((180-135)*M_PI/180)), 135);
    ht->rotateOf(atan(1/(1/tan((180-135)*M_PI/180)+0.1))*180/M_PI, -90, -90);
    ht->translateOf(1.25+i*space+i+space, 0.1, height-height/6+0.2);
    addObject(ht);
	
    Window* w = dynamic_cast<Window*>(archi->get("G_WINDOW"));
    w->set();
    w->translateOf(i*space+i+space, 0.2, height-1.5-height/6);
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
}

void WallWithStore::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
	objects->at(1)->setQuality(3);
	for (int i=2; i<(int)width/2.5+2; i++)
	  objects->at(i)->disable();
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
	objects->at(1)->setQuality(8);
	for (int i=2; i<(int)width/2.5+2; i++)
	  objects->at(i)->setQuality(5);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
	for (int i=2; i<(int)width/2.5+2; i++)
	  objects->at(i)->enable();
  }
}
