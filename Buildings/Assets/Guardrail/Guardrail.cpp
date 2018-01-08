#include "Guardrail.hpp"

Guardrail::Guardrail()
{
  type = "G_GUARDRAIL";
}

Guardrail::~Guardrail()
{
  ;
}

void Guardrail::set(float w, float h, float d, float s)
{
  width = w;
  height = h;
  depth = d;
  space = s;
  setBuiltIn();
  build();
}
