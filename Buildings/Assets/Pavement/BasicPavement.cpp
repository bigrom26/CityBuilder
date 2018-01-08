#include "BasicPavement.hpp"

BasicPavement::BasicPavement()
{
  style = CLASSIC;
}

void BasicPavement::setBuiltIn()
{
  bv = new AABB(height, width, depth);
  
  if ((nbRound < 0) || (nbRound > 4))
    nbRound = 4;
  
  for (int i=0; i<nbRound; i++)
  {
    Cylinder* c1 = new Cylinder(1, 0.15, M_PI/2);
    c1->rotateOf(0, 0, i*90);
	
	switch (i)
	{
	  case 0:
	    c1->translateOf(width-1, depth-1, 0);
		break;
	  case 1:
	    c1->translateOf(1, depth-1, 0);
		break;
	  case 2:
	    c1->translateOf(1, 1, 0);
		break;
	  default:
	    c1->translateOf(width-1, 1, 0);
		break;
	}
	
	addObject(c1);
  }
  
  for (int i=0; i<(4-nbRound); i++)
  {
    Box* b1 = new Box(0.15, 1, 1);
	
	switch (i)
	{
	  case 0:
	    b1->translateOf(width-1, 0, 0);
		break;
	  case 1:
	    b1->translateOf(0, 0, 0);
		break;
	  case 2:
	    b1->translateOf(0, depth-1, 0);
		break;
	  default:
	    b1->translateOf(width-1, depth-1, 0);
		break;
	}
	
	addObject(b1);
  }

  Box* b1 = new Box(height, width, depth-2);
  b1->translateOf(0, 1, 0);
  addObject(b1);
  
  Box* b2 = new Box(height, width-2, 1);
  b2->translateOf(1, 0, 0);
  addObject(b2);
  
  Box* b3 = new Box(height, width-2, 1);
  b3->translateOf(1, depth-1, 0);
  addObject(b3);
}
