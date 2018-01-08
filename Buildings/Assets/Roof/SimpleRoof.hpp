#ifndef _SIMPLEROOF_
#define _SIMPLEROOF_

#include "Roof.hpp"
#include <HappyTriangle.hpp>


class SimpleRoof : public Roof
{
  public :
    SimpleRoof();
    ~SimpleRoof();
  protected :
    void setBuiltIn();
};

#endif
