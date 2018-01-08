#ifndef _BUILDING_
#define _BUILDING_

#include <Asset.hpp>

/** @brief Represent a building front stage */
class Building : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    Building();
    ~Building();
    /**
      @brief Set params
      @param w The width of the entire building
      @param d The depth of the building
      @param nl The number of levels
    */
    void set(float w=15, float d=15, int nl=4);
  protected :
    virtual void setBuiltIn() =0;
    float width, depth;
    int nbLevel;
};

#endif
