#include <Architect.hpp>
#include "Tile_North_South.hpp"

Tile_North_South::Tile_North_South()
{
  style = CLASSIC;
  south = north = true;
}

void Tile_North_South::setBuiltIn()
{
  int roadSize = 8.0; // FIXME : make as parameter of connections
  bv = new AABB(size, size, 100/*taille plus haut immeuble*/);

  float blocSize = size;
  float blocWidth= size/2-roadSize/2;
  StreetBloc* b1 = dynamic_cast<StreetBloc*>(archi->get("G_STREETALLEY"));
  b1->set(blocSize,blocWidth);
  addAsset(b1);


  StreetBloc* b4 = dynamic_cast<StreetBloc*>(archi->get("G_STREETALLEY"));
  b4->set(blocSize,blocWidth);
  b4->rotateOf(0,0,180);
  b4->translateOf(size,size,0);
  addAsset(b4);
}
