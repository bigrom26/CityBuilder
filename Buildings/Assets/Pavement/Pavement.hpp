#ifndef _PAVEMENT_
#define _PAVEMENT_

#include <Asset.hpp>

/** @brief A generic Pavement class */
class Pavement : public Asset
{
  public :
    Pavement();
    ~Pavement();
    void set(float w=10, float d=10, int nr=4, float h=0.15);
  protected :
    virtual void setBuiltIn() =0;
    float width, depth, height;
	int nbRound;
};

#endif
