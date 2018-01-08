#ifndef _STREETBLOC_
#define _STREETBLOC_

#include "Asset.hpp"

/** @brief A streetbloc (pavement + buiding + streetlight...) */
class StreetBloc : public Asset
{
  public :
    /**
      @brief Default contructor
    */
    StreetBloc();
    ~StreetBloc();
    void set(float s ,float w=0);
  protected :
    virtual void setBuiltIn() =0;
    float size;
    float width; // Specify Bloc width
};
#endif
