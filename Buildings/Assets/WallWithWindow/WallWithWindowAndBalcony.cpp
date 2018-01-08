#include <Architect.hpp>
#include "WallWithWindowAndBalcony.hpp"

WallWithWindowAndBalcony::WallWithWindowAndBalcony()
{
  style = CLASSIC; // a titre d'exemple
}

/* Pas encore fini, juste un test pour commencer ! */
void WallWithWindowAndBalcony::setBuiltIn()
{
  int nbWin = (int)width/2.5;
  float depth = 1.0;
  float space = (width-nbWin*1)/(nbWin+1);
  float width_balcony = space/3*2+1;
  float depth_wall = 0.3;
  bv = new AABB(height+0.3, width, depth);
  bv->translateOf(0, 0.4-depth, -0.3);
  
  Wall* w_right = dynamic_cast<Wall*>(archi->get("G_WALL"));
  w_right->set(space, 2, depth_wall);
  w_right->translateOf(width-space, 0.1, 0);
  addAsset(w_right);
	
  Decoration* d1 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d1->set(space, 0.2);
  d1->translateOf(width-space, 0, height*2/3);
  addAsset(d1);
  
  Decoration* d2 = dynamic_cast<Decoration*>(archi->get("G_DECORATION"));
  d2->set(space, 0.2);
  d2->translateOf(width-space, 0, height/3);
  addAsset(d2);
  
  Box* topBox = new Box(height-2, width, depth_wall);
  topBox->translateOf(0, 0.1, 2);
  addObject(topBox); 
  
   for (int i=0; i<nbWin; i++)
  {		
    if (i%2 == 0)
    {
	  FrameDoor* f = dynamic_cast<FrameDoor*>(archi->get("G_FRAMEDOOR"));
      f->set();
      f->translateOf(i*space+i+space-0.1, 0, 0);
      addAsset(f);
	
      Window* w = dynamic_cast<Window*>(archi->get("G_WINDOW"));
      w->set(1, 2);
      w->translateOf(i*space+i+space, depth_wall/2, 0);
      addAsset(w);
	
      Balcony* b = dynamic_cast<Balcony*>(archi->get("G_BALCONY"));
      b->set(width_balcony, 1.5, depth-0.3);
      b->translateOf(i*space+i+2*space/3, 0.4-depth, -0.3);
      addAsset(b);
    }
	else
	{
	  FrameWindow* f = dynamic_cast<FrameWindow*>(archi->get("G_FRAMEWINDOW"));
      f->set(0.1, 1.4);
      f->translateOf(i*space+i+space-0.1, 0, 0.7);
      addAsset(f);
	
      Window* win = dynamic_cast<Window*>(archi->get("G_WINDOW"));
      win->set(1, 1.2);
      win->translateOf(i*space+i+space, depth_wall/2, 0.8);
      addAsset(win);
	  
	  Wall* w = dynamic_cast<Wall*>(archi->get("G_WALL"));
      w->set(1, 0.8, depth_wall);
      w->translateOf(i*space+i+space, 0.1, 0);
      addAsset(w);
	}
	
	Wall* w_left = dynamic_cast<Wall*>(archi->get("G_WALL"));
    w_left->set(space, 2, depth_wall);
    w_left->translateOf(i*space+i, 0.1, 0);
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

void WallWithWindowAndBalcony::_changeQuality(QUALITY q)
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
