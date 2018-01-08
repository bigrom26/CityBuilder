#ifndef _FRAMEWINDOW_
#define _FRAMEWINDOW_

#include <Asset.hpp>
#include <Box.hpp>

/** @brief A generic Frame window class */
class FrameWindow : public Asset
{
  public :
    FrameWindow();
    ~FrameWindow();
    void set(float w=0.1, float h=1.7, float s=1);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, space;
};
#endif
