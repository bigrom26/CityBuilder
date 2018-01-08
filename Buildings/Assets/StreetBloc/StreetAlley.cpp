#include <Architect.hpp>
#include "StreetAlley.hpp"

StreetAlley::StreetAlley()
{
  style = CLASSIC;
}

void StreetAlley::setBuiltIn()
{
  bv = new AABB(size, size, 100/*taille plus haut immeuble*/);
  
  /* FIRST District */
  int nb = rand()%10;
  Pavement* p = dynamic_cast<Pavement*>(archi->get("G_PAVEMENT"));
  p->set(size, width, 1);
  p->rotateOf(0, 0, 90);
  p->translateOf(size, 0, 0);
  addAsset(p);

  Building* b = dynamic_cast<Building*>(archi->get("G_BUILDING"));
  b->set(size-4, width-4, 5 + nb);
  b->rotateOf(0, 0, 90);
  b->translateOf(size - 2, 2, 0.15);
  addAsset(b);
  
  float corner = width -0.5;
  TrafficLight* tl = dynamic_cast<TrafficLight*>(archi->get("G_TRAFFICLIGHT"));
  tl->set(0.4, 4.5);
  tl->rotateOf(0,0,-90);
  tl->translateOf(corner-1.5, corner, 0.15);
  addAsset(tl);
  
  Streetlight* l1 = dynamic_cast<Streetlight*>(archi->get("G_STREETLIGHT"));
  l1->set(0.5, 3.5);
  l1->translateOf(corner, corner/4, 0.15);
  addAsset(l1);

  Streetlight* l2 = dynamic_cast<Streetlight*>(archi->get("G_STREETLIGHT"));
  l2->set(0.5, 3.5);
  l2->translateOf(corner, 3*corner/4, 0.15);
  addAsset(l2);

  Streetlight* l3 = dynamic_cast<Streetlight*>(archi->get("G_STREETLIGHT"));
  l3->set(0.5, 3.5);
  l3->translateOf(corner/4, corner, 0.15);
  addAsset(l3);

  Streetlight* l4 = dynamic_cast<Streetlight*>(archi->get("G_STREETLIGHT"));
  l4->set(0.5, 3.5);
  l4->translateOf(3*corner/4, corner, 0.15);
  addAsset(l4);
}
 
