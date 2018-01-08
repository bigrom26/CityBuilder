#ifndef _BAR_
#define _BAR_

#include "Decoration.hpp"


class Bar : public Decoration
{
  public :
    Bar();
    ~Bar();
	virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif
