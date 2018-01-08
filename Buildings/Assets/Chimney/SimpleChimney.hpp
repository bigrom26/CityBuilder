#ifndef _SIMPLECHIMNEY_
#define _SIMPLECHIMNEY_

#include "Chimney.hpp"


class SimpleChimney : public Chimney
{
  public :
    SimpleChimney();
    ~SimpleChimney();
  protected :
    void setBuiltIn();
};

#endif
