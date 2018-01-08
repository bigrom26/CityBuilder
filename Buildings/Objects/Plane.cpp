#include "Plane.hpp"

Plane::Plane(float w, float d, bool ts)
  : width(w), depth(d), twoSide(ts)
{
  bv = new AABB(0.01, w, d);
  build();
}

void Plane::rebuild(float w, float d, bool ts)
{
  width = w;
  depth = d;
  twoSide = ts;
  build();
}

void Plane::build() const
{
  glNewList(list, GL_COMPILE);
  glBegin(GL_QUADS);
  glNormal3f (0, 0, 1);
  glVertex3d (0, depth, 0);
  glVertex3d (0, 0, 0);
  glVertex3d (width, 0, 0);
  glVertex3d (width, depth, 0);
  glEnd();
  if(twoSide)
  {
    glBegin(GL_QUADS);
    glNormal3f (0, 0, -1);
    glVertex3d (0, depth, 0);
    glVertex3d (width, depth, 0);
    glVertex3d (width, 0, 0);
    glVertex3d (0, 0, 0);
    glEnd();
  }
  glEndList();
}
