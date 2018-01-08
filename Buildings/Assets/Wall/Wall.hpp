#ifndef _WALL_
#define _WALL_

#include "Asset.hpp"
#include <Box.hpp>

/** @brief Represent a wall */
class Wall : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Wall();
    ~Wall();
    /**
      @brief Set params
      @param w The width of the wall
      @param h The height of the wall
      @param d The depth of the wall
    */
    void set(float w=10, float h=3, float d=0.3);
  protected :
     virtual void setBuiltIn() =0;
    float width, height, depth;
};
#endif

