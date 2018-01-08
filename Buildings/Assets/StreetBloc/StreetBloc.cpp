#include "StreetBloc.hpp"

StreetBloc::StreetBloc()
{
  ;
}

StreetBloc::~StreetBloc()
{
  ;
}

void StreetBloc::set(float s, float w)
{
  size = s;
  width= w;
  setBuiltIn();
  build();
}
 
