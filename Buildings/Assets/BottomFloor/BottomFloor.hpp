#ifndef _BOTTOMFLOOR_
#define _BOTTOMFLOOR_

#include <Asset.hpp>
#include <Box.hpp>

/** @brief A generic Bottom floor class */
class BottomFloor : public Asset
{
  public :
    BottomFloor();
    ~BottomFloor();
    void set(float w=10, float h=3, float d=10);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, depth;
};
#endif
