#ifndef _COLUMN_
#define _COLUMN_

#include <Asset.hpp>

/** @brief A generic Column class */
class Column : public Asset
{
  public :
    Column();
    ~Column();
    void set(float w=0.3, float h=2);
  protected :
    virtual void setBuiltIn() =0;
    float width, height;
};
#endif
