#ifndef _STREETCORNER_
#define _STREETCORNER_

#include <AABB.hpp>
#include <Plane.hpp>
#include <Building.hpp>
#include <Pavement.hpp>
#include <Streetlight.hpp>
#include <TrafficLight.hpp>
#include "StreetBloc.hpp"

/** @brief A Corner of a street. */
class StreetCorner : public StreetBloc
{
  public :
    /**
      @brief Default contructor
    */
    StreetCorner();
    ~StreetCorner();
  protected :
    void setBuiltIn();
};
#endif
