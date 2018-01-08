#ifndef _GUARDRAILWITHCOLUMN_
#define _GUARDRAILWITHCOLUMN_

#include "Guardrail.hpp"
#include <Column.hpp>

class GuardrailWithColumn : public Guardrail
{
  public :
    GuardrailWithColumn();
    ~GuardrailWithColumn();
  protected :
    void setBuiltIn();
};

#endif
