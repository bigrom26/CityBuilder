#ifndef _FLATROOF_
#define _FLATROOF_

#include "Roof.hpp"

class FlatRoof : public Roof
{
  public :
    FlatRoof();
    ~FlatRoof();
  protected :
    void setBuiltIn();
};

#endif
