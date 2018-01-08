#ifndef _DECORATIONNULL_
#define _DECORATIONNULL_

#include "Decoration.hpp"


class DecorationNull : public Decoration
{
  public :
    DecorationNull();
    ~DecorationNull();
  protected :
    void setBuiltIn();
};

#endif
