#ifndef _WALLWITHWINDOW_
#define _WALLWITHWINDOW_

#include <Asset.hpp>

/** @brief Represent a building front stage */
class WallWithWindow : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    WallWithWindow();
    ~WallWithWindow();
    /**
      @brief Set params
      @param w The width of the entire wall
      @param h The height of the wall
      @param d The depth when there is a balcony
    */
    void set(float w=25, float h=3);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
