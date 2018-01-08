#ifndef _SIMPLECOLUMN_
#define _SIMPLECOLUMN_

#include "Column.hpp"
#include <Box.hpp>
#include <Cylinder.hpp>

class SimpleColumn : public Column
{
  public :
    SimpleColumn();
    ~SimpleColumn();
	 virtual void _changeQuality(QUALITY q);
  protected :
    void setBuiltIn();
};

#endif

