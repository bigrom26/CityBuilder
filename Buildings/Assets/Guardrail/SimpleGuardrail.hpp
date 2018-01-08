#ifndef _SIMPLEGUARDRAIL_
#define _SIMPLEGUARDRAIL_

#include "Guardrail.hpp"

class SimpleGuardrail : public Guardrail
{
  public :
    SimpleGuardrail();
    ~SimpleGuardrail();
  protected :
    void setBuiltIn();
};

#endif
