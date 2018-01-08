#ifndef _FRAMEDOOR_
#define _FRAMEDOOR_

#include "Asset.hpp"
#include <Box.hpp>

/** @brief A generic Frame door class */
class FrameDoor : public Asset
{
  public :
    FrameDoor();
    ~FrameDoor();
    void set(float w=0.1, float h=2.1, float s=1);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, space;
};
#endif
