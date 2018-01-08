#ifndef _FACTORYROOF_
#define _FACTORYROOF_

#include "FlatRoof.hpp"

class FactoryRoof : public FlatRoof
{
  public :
    FactoryRoof();
    ~FactoryRoof();
  protected :
    void setBuiltIn();
};

#endif
