#ifndef _CHIMNEY_
#define _CHIMNEY_

#include <Asset.hpp>

/** @brief Represent a chimney */
class Chimney : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Chimney();
    ~Chimney();
    /**
      @brief Set params
      @param w The width of the chimney
      @param h The height of the chimney
    */
    void set(float w=0.5, float h=1.5);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
