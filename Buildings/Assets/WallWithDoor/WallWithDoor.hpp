#ifndef _WALLWITHDOOR_
#define _WALLWITHDOOR_

#include <Asset.hpp>

/** @brief Represent a building front stage */
class WallWithDoor : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    WallWithDoor();
    ~WallWithDoor();
    /**
      @brief Set params
      @param w The width of the entire wall
      @param h The height of the wall
    */
    void set(float w=10, float h=3);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
