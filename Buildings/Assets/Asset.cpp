#include <Architect.hpp>
#include "Asset.hpp"

Asset::Asset(QUALITY q)
  : x(0), y(0), z(0), rx(0), ry(0), rz(0), quality(q)
{
  list = glGenLists(1);

  objects = new vector<Object*>();
  assets = new vector<Asset*>();
}

Asset::~Asset()
{
  /* delete objets */
  for(unsigned int i=0; i < objects->size(); i++)
    delete objects->at(i);
  delete objects;
  /* delete assets */
  for(unsigned int i=0; i<assets->size(); i++)
    delete assets->at(i);
  delete assets;
  glDeleteLists(list, 1);
}

void Asset::changeQuality(QUALITY q)
{
  quality = q;
  for(unsigned int i=0; i<assets->size(); i++)
    assets->at(i)->changeQuality(q);
  _changeQuality(q);
  build();
}

void Asset::_changeQuality(QUALITY)
{
  ; // does nothing... implements in specific assets
}

void Asset::addObject(Object* o)
{
  objects->push_back(o);
}

void Asset::addAsset(Asset* a)
{
  assets->push_back(a);
}

string Asset::getType() const
{
  return type;
}

void Asset::build()
{
  glNewList(list, GL_COMPILE);
  for(unsigned int i=0; i<assets->size(); i++)
    assets->at(i)->draw();
  for(unsigned int i=0; i<objects->size(); i++)
    if(objects->at(i)->isEnable())
      objects->at(i)->draw();
  glEndList();
}

void Asset::draw() const
{
  glPushMatrix();
  glTranslated(x,y,z);
  glRotated(rx, 1, 0, 0);
  glRotated(ry, 0, 1, 0);
  glRotated(rz, 0, 0, 1);
  glCallList(list);
  glPopMatrix();
}

void Asset::drawBV() const
{
  glPushMatrix();
  glTranslated(x,y,z);
  glRotated(rx, 1, 0, 0);
  glRotated(ry, 0, 1, 0);
  glRotated(rz, 0, 0, 1);
  bv->draw();
  glPopMatrix();
}

void Asset::drawBVR(int depth) const
{
  if(depth > 0)
  {
    glPushMatrix();
    glTranslated(x,y,z);
    glRotated(rx, 1, 0, 0);
    glRotated(ry, 0, 1, 0);
    glRotated(rz, 0, 0, 1);
    for(unsigned int i=0; i<assets->size(); i++)
    {
      assets->at(i)->drawBV();
      assets->at(i)->drawBVR(depth--);
    }
    for(unsigned int i=0; i<objects->size();i++)
      objects->at(i)->drawBV();
    glPopMatrix();
  }
}

void Asset::moveTo(float _x, float _y, float _z)
{
  x = _x;
  y = _y;
  z = _z;
}

void Asset::translateOf(float _x, float _y, float _z)
{
  x += _x;
  y += _y;
  z += _z;
}

void Asset::rotateOf(float _rx, float _ry, float _rz)
{
  rx += _rx;
  ry += _ry;
  rz += _rz;
}

BV* Asset::getBV() const
{
  return bv;
}

void Asset::setArchitect(Architect* a)
{
   archi = a;
}
