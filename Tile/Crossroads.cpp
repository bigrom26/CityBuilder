#include <Architect.hpp>
#include "Crossroads.hpp"

Crossroads::Crossroads()
{
  style = CLASSIC;
  west = east = south = north = true;
}

void Crossroads::setBuiltIn()
{
  int roadSize = 8.0; // FIXME : make as parameter of connections
  bv = new AABB(size, size, 100/*taille plus haut immeuble*/);
  
  float blocSize = size/2-roadSize/2;
  StreetBloc* b1 = dynamic_cast<StreetBloc*>(archi->get("G_STREETBLOC"));
  b1->set(blocSize,0);
  addAsset(b1);

  StreetBloc* b2 = dynamic_cast<StreetBloc*>(archi->get("G_STREETBLOC"));
  b2->set(blocSize,0);
  b2->rotateOf(0,0,90);
  b2->translateOf(size,0,0);
  addAsset(b2);

  StreetBloc* b3 = dynamic_cast<StreetBloc*>(archi->get("G_STREETBLOC"));
  b3->set(blocSize,0);
  b3->rotateOf(0,0,-90);
  b3->translateOf(0,size,0);
  addAsset(b3);

  StreetBloc* b4 = dynamic_cast<StreetBloc*>(archi->get("G_STREETBLOC"));
  b4->set(blocSize,0);
  b4->rotateOf(0,0,180);
  b4->translateOf(size,size,0);
  addAsset(b4);
}
