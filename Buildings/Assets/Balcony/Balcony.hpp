#ifndef _BALCONY_
#define _BALCONY_

#include <Asset.hpp>

/** @brief Represent a balcony */
class Balcony : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Balcony();
    ~Balcony();
    /**
      @brief Set params
      @param w The width of the balcony
      @param h The height of the balcony
      @param d The depth of the balcony
    */
    void set(float w=5, float h=1.5, float d=5);
  protected :
    virtual void setBuiltIn() =0;
    float width, height, depth;
};
#endif
