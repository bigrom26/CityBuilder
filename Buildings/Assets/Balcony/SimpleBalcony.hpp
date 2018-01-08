#ifndef _SIMPLEBALCONY_
#define _SIMPLEBALCONY_

#include <Balcony.hpp>
#include <Guardrail.hpp>
#include <Box.hpp>


class SimpleBalcony : public Balcony
{
  public :
    SimpleBalcony();
    ~SimpleBalcony();
  protected :
    void setBuiltIn();
};

#endif
