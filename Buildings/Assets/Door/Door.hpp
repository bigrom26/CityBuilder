#ifndef _DOOR_
#define _DOOR_

#include <Asset.hpp>
#include <Box.hpp>

/** @brief A generic Door class */
class Door : public Asset
{
  public :
    Door();
    ~Door();
    void set(float w=1, float h=2);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
