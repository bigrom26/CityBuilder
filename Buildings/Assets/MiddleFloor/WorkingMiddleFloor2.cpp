#include <Architect.hpp>
#include "WorkingMiddleFloor2.hpp"
#include <math.h>

WorkingMiddleFloor2::WorkingMiddleFloor2()
{
  style = CLASSIC; // a titre d'exemple
}

void WorkingMiddleFloor2::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  Box* ceiling = new Box(0.3, width-(2*0.4), depth-(2*0.4));
  ceiling->translateOf(0.4, 0.4, height-0.3);
  addObject(ceiling);
  
  Box* w_front = new Box(height, width-0.2, 0.3);
  w_front->translateOf(0.1, 0.1, 0);
  addObject(w_front);
  
  Box* w_back = new Box(height, width-0.2, 0.3);
  w_back->translateOf(0.1, depth-0.4, 0);
  addObject(w_back);
  
  float width_begin = (width-0.2-floor(width-0.2))/2+0.1;
  
  for (float i=width_begin; i<(width-1.1); i+=2)
  {
    Box* b1 = new Box(1, 0.9, 0.1);
    b1->translateOf(i, 0, 0);
    addObject(b1);

    Box* b2 = new Box(1.3, 0.9, 0.1);
    b2->translateOf(i, 0, 1.1);
    addObject(b2);

    Box* b3 = new Box(0.4, 0.9, 0.1);
    b3->translateOf(i, 0, 2.5);
    addObject(b3);
    
    Box* b4 = new Box(1, 0.9, 0.1);
    b4->translateOf(i, depth-0.1, 0);
    addObject(b4);
    
    Box* b5 = new Box(1.3, 0.9, 0.1);
    b5->translateOf(i, depth-0.1, 1.1);
    addObject(b5);
    
    Box* b6 = new Box(0.4, 0.9, 0.1);
    b6->translateOf(i, depth-0.1, 2.5);
    addObject(b6);
  }
  
  Box* w_left = new Box(height, 0.3, depth-0.8);
  w_left->translateOf(0.1, 0.4, 0);
  addObject(w_left);
  
  Box* w_right = new Box(height, 0.3, depth-0.8);
  w_right->translateOf(width-0.4, 0.4, 0);
  addObject(w_right);
  
  float depth_begin = (depth-0.2-floor(depth-0.2))/2+0.1;
  
  for (float i=depth_begin; i<(depth-1.1); i+=2)
  {
    Box* b1 = new Box(1, 0.9, 0.1);
    b1->rotateOf(0, 0, 90);
    b1->translateOf(0.1, i, 0);
    addObject(b1);
	
    Box* b2 = new Box(1.3, 0.9, 0.1);
    b2->rotateOf(0, 0, 90);
    b2->translateOf(0.1, i, 1.1);
    addObject(b2);
    
    Box* b3 = new Box(0.4, 0.9, 0.1);
    b3->rotateOf(0, 0, 90);
    b3->translateOf(0.1, i, 2.5);
    addObject(b3);
    
    Box* b4 = new Box(1, 0.9, 0.1);
    b4->rotateOf(0, 0, 90);
    b4->translateOf(width, i, 0);
    addObject(b4);
    
    Box* b5 = new Box(1.3, 0.9, 0.1);
    b5->rotateOf(0, 0, 90);
    b5->translateOf(width, i, 1.1);
    addObject(b5);
    
    Box* b6 = new Box(0.4, 0.9, 0.1);
    b6->rotateOf(0, 0, 90);
    b6->translateOf(width, i, 2.5);
    addObject(b6);
  }
}
