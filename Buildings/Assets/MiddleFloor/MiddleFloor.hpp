#ifndef _MIDDLEFLOOR_
#define _MIDDLEFLOOR_

#include <Asset.hpp>
#include <Box.hpp>

/** @brief A generic Middle floor class */
class MiddleFloor : public Asset
{
  public :
    MiddleFloor();
    ~MiddleFloor();
    void set(float w=10, float h=3, float d=10);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, depth;
};
#endif
