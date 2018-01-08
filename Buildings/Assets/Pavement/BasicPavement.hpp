#ifndef _BASICPAVEMENT_
#define _BASICPAVEMENT_

#include "Pavement.hpp"
#include <Box.hpp>
#include <Cylinder.hpp>

class BasicPavement : public Pavement
{
  public :
    BasicPavement();
    ~BasicPavement();
  protected :
    void setBuiltIn();
};

#endif
