#include "AABB.hpp"

AABB::AABB(float h, float w, float d)
  : height(h), width(w), depth(d)
{
  ;
}

void AABB::paintGL() const
{

/*
  //top
  glBegin(GL_LINE_STRIP);
  glVertex3d (0, 0, 0);
  glVertex3d (0, 0, height);
  glVertex3d (width, 0, height);
  glVertex3d (width, 0, 0);
  glVertex3d (0, 0, 0);
  glEnd();
  //bottom
  glBegin(GL_LINE_STRIP);
  glVertex3d (0, depth, 0);
  glVertex3d (0, depth, height);
  glVertex3d (width, depth, height);
  glVertex3d (width, depth, 0);
  glVertex3d (0, depth, 0);
  glEnd();
  //left
  glBegin(GL_LINES);
  glVertex3d (0, 0, 0);
  glVertex3d (0, depth, 0);
  glEnd();
  //right
  glBegin(GL_LINES);
  glVertex3d (width, 0, 0);
  glVertex3d (width, depth, 0);
  glEnd();
  //back
  glBegin(GL_LINES);
  glVertex3d (0, 0, height);
  glVertex3d (0, depth, height);
  glEnd();
  //front
  glBegin(GL_LINES);
  glVertex3d (width, 0, height);
  glVertex3d (width, depth, height);
  glEnd();
*/
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
}
