#include "BV.hpp"

BV::BV()
  : x(0), y(0), z(0), rx(0), ry(0), rz(0)
{
  ;
}

void BV::moveTo(float _x, float _y, float _z)
{
  x = _x;
  y = _y;
  z = _z;
}

void BV::draw() const
{
  GLboolean lighting;
  glGetBooleanv(GL_LIGHTING, &lighting);
  //GLfloat color[4];
  //glGetFloatv(GL_CURRENT_COLOR, &color[0]);
  glDisable(GL_LIGHTING);
  //glColor3f(0.0, 1.0, 0.0);
  glPushMatrix();
  glRotated(rx, 1, 0, 0);
  glRotated(ry, 0, 1, 0);
  glRotated(rz, 0, 0, 1);
  glTranslated(x, y, z);
  // paintGL call
  paintGL();
  glPopMatrix();
  //glColor3f(color[0], color[1], color[2]);
  if (lighting)
    glEnable(GL_LIGHTING);
}

void BV::translateOf(float _x, float _y, float _z)
{
  x += _x;
  y += _y;
  z += _z;
}

void BV::rotateOf(float _rx, float _ry, float _rz)
{
  rx += _rx;
  ry += _ry;
  rz += _rz;
}

float BV::getX() const
{
  return x;
}

float BV::getY() const
{
  return y;
}
