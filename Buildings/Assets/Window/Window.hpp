#ifndef _WINDOW_
#define _WINDOW_

#include <Asset.hpp>

/** @brief A generic Window class */
class Window : public Asset
{
  public :
    Window();
    ~Window();
    void set(float w=1, float h=1.5);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};

#endif
