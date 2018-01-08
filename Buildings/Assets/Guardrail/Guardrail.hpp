#ifndef _GUARDRAIL_
#define _GUARDRAIL_

#include <Asset.hpp>
#include <Box.hpp>

/** @brief A generic Guardrail class */
class Guardrail : public Asset
{
  public :
    Guardrail();
    ~Guardrail();
    void set(float w=2, float h=0.8, float d=0.1, float s=0.3);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, depth, space;
};
#endif
