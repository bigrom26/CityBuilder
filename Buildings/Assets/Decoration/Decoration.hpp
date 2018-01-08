#ifndef _DECORATION_
#define _DECORATION_

#include "Asset.hpp"
#include <Box.hpp>

/** @brief Represent a wall */
class Decoration : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Decoration();
    ~Decoration();
    /**
      @brief Set params
      @param w The width of the decoration
      @param h The height of the decoration
    */
    void set(float w=1, float h=0.2);
  protected :
     virtual void setBuiltIn() =0;
    float width, height;
};
#endif

