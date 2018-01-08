#include <Architect.hpp>
#include "WorkingTopFloor.hpp"

WorkingTopFloor::WorkingTopFloor()
{
  style = CLASSIC; // a titre d'exemple
}

void WorkingTopFloor::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  Box* ceiling = new Box(0.3, width-(2*0.6), depth-(2*0.6));
  ceiling->translateOf(0.6, 0.6, height-0.3);
  addObject(ceiling);
  
  Box* w_front = new Box(height, width-0.6, 0.3);
  w_front->translateOf(0.3, 0.3, 0);
  addObject(w_front);
  
  HappyTriangle* ht1 = new HappyTriangle(width-0.6, 0.3, 0.3, 90);
  ht1->rotateOf(0, 90, -90);
  ht1->translateOf(0.3, 0.3, height);
  addObject(ht1);
  
  Box* w_back = new Box(height, width-0.6, 0.3);
  w_back->translateOf(0.3, depth-0.6, 0);
  addObject(w_back);
 
  HappyTriangle* ht2 = new HappyTriangle(width-0.6, 0.3, 0.3, 90);
  ht2->rotateOf(0, 90, 0);
  ht2->translateOf(0.3, depth-0.3, height);
  addObject(ht2);
  
  float width_begin = (width-0.6-floor(width-0.6))/2+0.1;
  
  for (float i=width_begin; i<(width-1.1); i++)
  {
    Box* b1 = new Box(1, 0.9, 0.1);
    b1->translateOf(i, 0.2, 0);
    addObject(b1);
    
    Box* b2 = new Box(1.3, 0.9, 0.1);
    b2->translateOf(i, 0.2, 1.1);
    addObject(b2);
    
    Box* b4 = new Box(1, 0.9, 0.1);
    b4->translateOf(i, depth-0.3, 0);
    addObject(b4);
    
    Box* b5 = new Box(1.3, 0.9, 0.1);
    b5->translateOf(i, depth-0.3, 1.1);
    addObject(b5);
  }
  
  Box* w_left = new Box(height, 0.3, depth-1.2);
  w_left->translateOf(0.3, 0.6, 0);
  addObject(w_left);
  
  HappyTriangle* ht3 = new HappyTriangle(depth-0.6, 0.3, 0.3, 90);
  ht3->rotateOf(90, 0, 180);
  ht3->translateOf(0.3, depth-0.3, height);
  addObject(ht3);
  
  Box* w_right = new Box(height, 0.3, depth-1.2);
  w_right->translateOf(width-0.6, 0.6, 0);
  addObject(w_right);
  
  HappyTriangle* ht4 = new HappyTriangle(depth-0.6, 0.3, 0.3, 90);
  ht4->rotateOf(90, 0, -90);
  ht4->translateOf(width-0.3, depth-0.3, height);
  addObject(ht4);
  
  float depth_begin = (depth-0.6-floor(depth-0.6))/2+0.1;
  
  for (float i=depth_begin; i<(depth-1.1); i++)
  {
    Box* b1 = new Box(1, 0.9, 0.1);
	b1->rotateOf(0, 0, 90);
    b1->translateOf(0.3, i, 0);
    addObject(b1);
	
    Box* b2 = new Box(1.3, 0.9, 0.1);
    b2->rotateOf(0, 0, 90);
    b2->translateOf(0.3, i, 1.1);
    addObject(b2);
	
    Box* b4 = new Box(1, 0.9, 0.1);
    b4->rotateOf(0, 0, 90);
    b4->translateOf(width-0.2, i, 0);
    addObject(b4);
	
    Box* b5 = new Box(1.3, 0.9, 0.1);
    b5->rotateOf(0, 0, 90);
    b5->translateOf(width-0.2, i, 1.1);
    addObject(b5);
  } 
}
