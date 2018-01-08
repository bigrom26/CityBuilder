#include <Architect.hpp>
#include <Guardrail.hpp>
#include "WallWithInBalcony.hpp"

WallWithInBalcony::WallWithInBalcony()
{
  style = CLASSIC; // a titre d'exemple
}

/* Pas encore fini, juste un test pour commencer ! */
void WallWithInBalcony::setBuiltIn()
{
  int nbWin = (int)width/2.5;
  float depth = 0.3;
  float depth_total = 2.3;
  float space = (width-nbWin*1)/(nbWin+1);
  bv = new AABB(height, width, depth_total+0.1);
  for (int i=0; i<nbWin/3; i++)
  {
    FrameWindow* f = dynamic_cast<FrameWindow*>(archi->get("G_FRAMEWINDOW"));
    f->set();
    f->translateOf(i*space+i+space-0.1, 0, height-1.5-height/6-0.1);
    addAsset(f);
	
    Window* w = dynamic_cast<Window*>(archi->get("G_WINDOW"));
    w->set();
    w->translateOf(i*space+i+space, depth/2, height-1.5-height/6);
    addAsset(w);
	
    Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d1->set(space, 0.2);
    d1->translateOf(i*space+i, 0, height/3);
    addAsset(d1);
	
    Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d2->set(space, 0.2);
    d2->translateOf(i*space+i, 0, height*2/3);
    addAsset(d2);  
	
	Wall* w_left = dynamic_cast<Wall*>(archi->get("G_WALL"));
    w_left->set(space, 1.5, depth);
    w_left->translateOf(i*space+i, 0.1, height-1.5-height/6);
    addAsset(w_left);

	if (i < (int)(nbWin/3)-1)
    {
	  FrameWindow* f2 = dynamic_cast<FrameWindow*>(archi->get("G_FRAMEWINDOW"));
      f2->set();
      f2->translateOf((nbWin-i)*space+nbWin-i-1.1, 0, height-1.5-height/6-0.1);
      addAsset(f2);
	  
	  Window* w2 = dynamic_cast<Window*>(archi->get("G_WINDOW"));
      w2->set();
      w2->translateOf((nbWin-i)*space+nbWin-i-1, depth/2, height-1.5-height/6);
      addAsset(w2);
	  
	  if (i < (int)(nbWin/3)-2)
      {
		Wall* w_left2 = dynamic_cast<Wall*>(archi->get("G_WALL"));
		w_left2->set(space, 1.5, depth);
		w_left2->translateOf((nbWin-i)*space+(nbWin-i-space-1), 0.1, height-1.5-height/6);
		addAsset(w_left2);  

		Decoration* d3 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  	    d3->set(space, 0.2);	  
		d3->translateOf((nbWin-i)*space+(nbWin-i-space-1), 0, height/3);
		addAsset(d3);
		  
		Decoration* d4 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
		d4->set(space, 0.2);
		d4->translateOf((nbWin-i)*space+(nbWin-i-space-1), 0, height*2/3);
		addAsset(d4);
	  }
	} 
  }
  
  for (int i=nbWin/3; i<nbWin*2/3; i++)
  {
	FrameDoor* f = dynamic_cast<FrameDoor*>(archi->get("G_FRAMEDOOR"));
    f->set();
    f->translateOf(i*space+i+2*space-0.1, 2, 0);
    addAsset(f);
	
    Window* w = dynamic_cast<Window*>(archi->get("G_WINDOW"));
    w->set(1, 2);
    w->translateOf(i*space+i+2*space, depth_total-depth/2, 0);
    addAsset(w);
	
    Wall* w_left = dynamic_cast<Wall*>(archi->get("G_WALL"));
    w_left->set(space, 2, depth);
    w_left->translateOf(i*space+i+space, 2.1, 0);
    addAsset(w_left);
	
    Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d1->set(space, 0.2);
    d1->translateOf(i*space+i+space, 2, height/3);
    addAsset(d1);
	
    Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
    d2->set(space, 0.2);
    d2->translateOf(i*space+i+space, 2, height*2/3);
    addAsset(d2);
  }
  
  Wall* w_left2 = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_left2->set(space, 2, depth);
  w_left2->translateOf((nbWin*2/3-1)*space+(nbWin*2/3-1)+2*space+1, 2.1, 0);
  addAsset(w_left2);  

  Decoration* d01 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d01->set(space, 0.2);	  
  d01->translateOf((nbWin*2/3-1)*space+(nbWin*2/3-1)+2*space+1, 2, height/3);
  addAsset(d01);
		  
  Decoration* d02 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d02->set(space, 0.2);
  d02->translateOf((nbWin*2/3-1)*space+(nbWin*2/3-1)+2*space+1, 2, height*2/3);
  addAsset(d02);
  
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
  
  Wall* w_right2 = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_right2->set(space, 1.5, depth);
  w_right2->translateOf((space+1)*(int)(nbWin/3), 0.1, height-1.5-height/6);
  addAsset(w_right2);
  
  Decoration* d3 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d3->set(space, 0.2);
  d3->translateOf((space+1)*(int)(nbWin/3), 0, height/3);
  addAsset(d3);
	
  Decoration* d4 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d4->set(space, 0.2);
  d4->translateOf((space+1)*(int)(nbWin/3), 0, height*2/3);
  addAsset(d4);
  
  Box* bottomBox1 = new Box(height-1.5-height/6, (space+1)*(int)(nbWin/3)+space, depth);
  bottomBox1->translateOf(0, 0.1, 0);
  addObject(bottomBox1);
  
  Box* topBox1 = new Box(height/6, (space+1)*(int)(nbWin/3)+space, depth);
  topBox1->translateOf(0, 0.1, height-height/6);
  addObject(topBox1); 
  
  Box* bottomBox2 = new Box(height-1.5-height/6, width-((space+1)*(int)(nbWin*2/3)+2*space+1), depth);
  bottomBox2->translateOf((space+1)*(int)(nbWin*2/3)+2*space+1, 0.1, 0);
  addObject(bottomBox2);
  
  Box* topBox2 = new Box(height/6, width-((space+1)*(int)(nbWin*2/3)+2*space+1), depth);
  topBox2->translateOf((space+1)*(int)(nbWin*2/3)+2*space+1, 0.1, height-height/6);
  addObject(topBox2); 
  
  Box* topBox3 = new Box(1, (space+1)*(int)(nbWin/3)+space, depth);
  topBox3->translateOf((space+1)*(int)(nbWin/3)+space, 2.1, 2);
  addObject(topBox3);
  
  Wall* w_right3 = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_right3->set(1, 3, depth);
  w_right3->translateOf((space+1)*(int)(nbWin*2/3)+2*space, 0.1, 0);
  addAsset(w_right3);
  
  Decoration* d5 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d5->set(1, 0.2);
  d5->translateOf((space+1)*(int)(nbWin*2/3)+2*space, 0, height/3);
  addAsset(d5);
	
  Decoration* d6 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d6->set(1, 0.2);
  d6->translateOf((space+1)*(int)(nbWin*2/3)+2*space, 0, height*2/3);
  addAsset(d6);
  
  Box* b1 = new Box(height, depth, 2);
  b1->translateOf(nbWin/3*space+nbWin/3+space-0.3, 0.4, 0);
  addObject(b1);
  
  Box* b2 = new Box(height, depth, 2);
  b2->translateOf((space+1)*(int)(nbWin*2/3)+2*space, 0.4, 0);
  addObject(b2);
  
  Guardrail* g = dynamic_cast<Guardrail*>(archi->get("G_GUARDRAIL"));
  g->set(((space+1)*(int)(nbWin*2/3)+2*space)-(nbWin/3*space+nbWin/3+space));
  g->translateOf(nbWin/3*space+nbWin/3+space, 0.2, 0);
  addAsset(g);
}

void WallWithInBalcony::_changeQuality(QUALITY q)
{
  if(q == LOW)
  {
    objects->at(0)->setQuality(3);
	objects->at(1)->setQuality(3);
	objects->at(2)->setQuality(3);
	objects->at(3)->setQuality(3);
	objects->at(4)->setQuality(3);
	objects->at(5)->setQuality(3);
	objects->at(6)->setQuality(3);
  }
  else if(q == MEDIUM)
  {
	objects->at(0)->setQuality(8);
	objects->at(1)->setQuality(8);
	objects->at(2)->setQuality(8);
	objects->at(3)->setQuality(8);
	objects->at(4)->setQuality(8);
	objects->at(5)->setQuality(8);
	objects->at(6)->setQuality(8);
  }
  else if(q == HIGHT)
  {
    objects->at(0)->enable();
	objects->at(1)->enable();
	objects->at(2)->enable();
	objects->at(3)->enable();
	objects->at(4)->enable();
	objects->at(5)->enable();
	objects->at(6)->enable();
  }
}
