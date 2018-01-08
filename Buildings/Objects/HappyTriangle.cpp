#include "HappyTriangle.hpp"

HappyTriangle::HappyTriangle(float h, float w, float d, float a)
  : height(h), width(w), depth(d), angle(a)
{
  float dist, x_point;
  dist = depth / (fabs(cos(angle)));

  if (angle <= 90)
	x_point = sqrt(dist*dist - depth*depth);
  else
	x_point = -sqrt(dist*dist - depth*depth);

  bv = new AABB(height, (x_point<0?width-x_point:(x_point>width?x_point:width)), depth);
  bv->translateOf((x_point<0?x_point:0), 0, 0);
  build();
}

void HappyTriangle::rebuild(float h, float w, float d, float a)
{
  height = h;
  width = w;
  depth = d;
  angle = a;
  build();
}

void HappyTriangle::build() const
{
  float x_point, x_edge1, y_edge1, z_edge1, x_edge2, y_edge2, z_edge2;
  Vector<> v1, v2, normal;
  glNewList(list, GL_COMPILE);

  x_point = depth / tan(angle*M_PI/180);

  //top
  glBegin(GL_TRIANGLES);
  glNormal3f (0, 0, 1);
  glVertex3d (width, 0, height);
  glVertex3d (x_point, depth, height);
  glVertex3d (0, 0, height);
  glEnd();

  //bottom
  glBegin(GL_TRIANGLES);
  glNormal3f (0, 0, -1);
  glVertex3d (width, 0, 0);
  glVertex3d (0, 0, 0);
  glVertex3d (x_point, depth, 0);
  glEnd();

  //left
  x_edge1 = -x_point;
  y_edge1 = -depth;
  z_edge1 = 0;
  x_edge2 = 0;
  y_edge2 = 0;
  z_edge2 = height;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  normal = v1 ^ v2;
  normal.normalize();
  glBegin(GL_QUADS);
  glNormal3f (normal.x, normal.y, normal.z);
  glVertex3d (x_point, depth, 0);
  glVertex3d (0, 0, 0);
  glVertex3d (0, 0, height);
  glVertex3d (x_point, depth, height);
  glEnd();

  //back
  x_edge1 = 0;
  y_edge1 = 0;
  z_edge1 = height;
  x_edge2 = width - x_point;
  y_edge2 = -depth;
  z_edge2 = 0;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  normal = v1 ^ v2;
  normal.normalize();
  glBegin(GL_QUADS);
  glNormal3f (normal.x, normal.y, normal.z);
  glVertex3d (width, 0, 0);
  glVertex3d (x_point, depth, 0);
  glVertex3d (x_point, depth, height);
  glVertex3d (width, 0, height);
  glEnd();

  //front
  glBegin(GL_QUADS);
  glNormal3f (0, -1, 0);
  glVertex3d (0, 0, 0);
  glVertex3d (width, 0, 0);
  glVertex3d (width, 0, height);
  glVertex3d (0, 0, height);
  glEnd();
  glEndList();
}
