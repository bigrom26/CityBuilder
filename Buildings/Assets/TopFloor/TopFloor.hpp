#ifndef _TOPFLOOR_
#define _TOPFLOOR_

#include <Asset.hpp>
#include <Box.hpp>

/** @brief A generic Top floor class */
class TopFloor : public Asset
{
  public :
    TopFloor();
    ~TopFloor();
    void set(float w=10, float h=3, float d=10);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, depth;
};
#endif
