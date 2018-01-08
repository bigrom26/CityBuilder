#include "Box.hpp"

Box::Box(float h, float w, float d)
  : height(h), width(w), depth(d)
{
  bv = new AABB(h, w, d);
  build();
}

void Box::rebuild(float h, float w, float d)
{
  height = h;
  width = w;
  depth = d;
  build();
}

void Box::build() const
{
  glNewList(list, GL_COMPILE);
  //top
  glBegin(GL_QUADS);
  glNormal3f (0, 0, 1);
  glVertex3d (0, depth, height);
  glVertex3d (0, 0, height);
  glVertex3d (width, 0, height);
  glVertex3d (width, depth, height);
  glEnd();
  //bottom
  glBegin(GL_QUADS);
  glNormal3f (0, 0, -1);
  glVertex3d (0, depth, 0);
  glVertex3d (width, depth, 0);
  glVertex3d (width, 0, 0);
  glVertex3d (0, 0, 0);
  glEnd();
  //left
  glBegin(GL_QUADS);
  glNormal3f (-1, 0, 0);
  glVertex3d (0, 0, height);
  glVertex3d (0, depth, height);
  glVertex3d (0, depth, 0);
  glVertex3d (0, 0, 0);
  glEnd();
  //right
  glBegin(GL_QUADS);
  glNormal3f (1, 0, 0);
  glVertex3d (width, depth, 0);
  glVertex3d (width, depth, height);
  glVertex3d (width, 0, height);
  glVertex3d (width, 0, 0);
  glEnd();
  //back
  glBegin(GL_QUADS);
  glNormal3f (0, 1, 0);
  glVertex3d (0, depth, 0);
  glVertex3d (0, depth, height);
  glVertex3d (width, depth, height);
  glVertex3d (width, depth, 0);
  glEnd();
  //front
  glBegin(GL_QUADS);
  glNormal3f (0, -1, 0);
  glVertex3d (width, 0, height);
  glVertex3d (0, 0, height);
  glVertex3d (0, 0, 0);
  glVertex3d (width, 0, 0);
  glEnd();
  glEndList();
}
