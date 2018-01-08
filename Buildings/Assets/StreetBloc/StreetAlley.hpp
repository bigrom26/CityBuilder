#ifndef _STREETALLEY_
#define _STREETALLEY_

#include <AABB.hpp>
#include <Plane.hpp>
#include <Building.hpp>
#include <Pavement.hpp>
#include <Streetlight.hpp>
#include <TrafficLight.hpp>
#include "StreetBloc.hpp"

/** @brief A Corner of a street. */
class StreetAlley : public StreetBloc
{
  public :
    /**
      @brief Default contructor
    */
    StreetAlley();
    ~StreetAlley();
  protected :
    void setBuiltIn();
};
#endif
