#include "Object.hpp"

Object::Object()
  : x(0), y(0), z(0), rx(0), ry(0), rz(0), alpha(1.0), _enable(true)
{
  list = glGenLists(1);
}

Object::~Object()
{
  glDeleteLists(list, 1);
  delete bv;
}

void Object::enable()
{
  _enable = true;
}

void Object::disable()
{
  _enable = false;
}
void Object::toogle()
{
  _enable = !_enable;
}

bool Object::isEnable() const
{
  return _enable;
}

void Object::moveTo(float _x, float _y, float _z)
{
  x = _x;
  y = _y;
  z = _z;
  bv->moveTo(x, y, z);
}

void Object::draw() const
{
  GLfloat color[4];
  if(alpha != 1.0)
  {
    glDepthMask(GL_FALSE);
    glGetFloatv(GL_CURRENT_COLOR, &color[0]);
    glColor4f(0.0f, 0.5f, 0.5f, alpha);
  }
  glPushMatrix();
  glTranslated(x, y, z);
  glRotated(rx, 1, 0, 0);
  glRotated(ry, 0, 1, 0);
  glRotated(rz, 0, 0, 1);
  glCallList(list);
  glPopMatrix();

  if(alpha != 1.0) { glDepthMask(GL_TRUE);
    glColor4f(color[0], color[1], color[2], 1.0);}
}

void Object::drawBV() const
{
  glPushMatrix();
  glTranslated(x, y, z);
  glRotated(rx, 1, 0, 0);
  glRotated(ry, 0, 1, 0);
  glRotated(rz, 0, 0, 1);
  bv->draw();
  glPopMatrix();
}

BV* Object::getBV() const
{
  return bv;
}

void Object::translateOf(float _x, float _y, float _z)
{
  x += _x;
  y += _y;
  z += _z;
}

void Object::rotateOf(float _rx, float _ry, float _rz)
{
  rx += _rx;
  ry += _ry;
  rz += _rz;
}

void Object::setTransparency(float a)
{
  alpha = a;
}