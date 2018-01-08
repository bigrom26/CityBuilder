#include "HappyBox.hpp"

float max(float a, float b)
{
  return (a>b? a : b);
}

float min(float a, float b)
{
  return (a<=b? a : b);
}

HappyBox::HappyBox(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
  float x_min, y_min, z_min, x_max, y_max, z_max;
  x_min = min(0, x1);
  x_max = max(x2, x3);
  y_min = min(0, y3);
  y_max = max(y1, y2);
  z_min = min(0, z1);
  z_max = max(z2, z3);
  bv = new AABB(z_max-z_min, x_max-x_min, y_max-y_min);
  bv->translateOf(x_min, y_min, z_min);
  rebuild(x1, y1, z1, x2, y2, z2, x3, y3, z3);
}

void HappyBox::rebuild(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
  abs1 = x1;
  ord1 = z1;
  dep1 = y1;
  abs2 = x2;
  ord2 = z2;
  dep2 = y2;
  abs3 = x3;
  ord3 = z3;
  dep3 = y3;
  build();
}

void HappyBox::build() const
{
  float x_edge1, y_edge1, z_edge1, x_edge2, y_edge2, z_edge2;
  glNewList(list, GL_COMPILE);
  Vector<> v1, v2, v3;

  //top
  x_edge1 = 0;
  y_edge1 = dep2 - dep1;
  z_edge1 = 0;
  x_edge2 = abs2 - abs1;
  y_edge2 = 0;
  z_edge2 = ord2 - ord1;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  v3 = v2 ^ v1;
  v3.normalize();
  glBegin(GL_QUADS);
  glNormal3f (v3.x, v3.y, v3.z);
  glVertex3d (abs2, dep1, ord1);
  glVertex3d (abs2, dep2, ord2);
  glVertex3d (abs1, dep2, ord2);
  glVertex3d (abs1, dep1, ord1);
  glEnd();

  //bottom
  x_edge1 = 0;
  y_edge1 = 0 - dep3;
  z_edge1 = 0 - ord3;
  x_edge2 = abs3 - 0;
  y_edge2 = 0;
  z_edge2 = 0;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  v3 = v2 ^ v1;
  v3.normalize();
  glBegin(GL_QUADS);
  glNormal3f (v3.x, v3.y, v3.z);
  glVertex3d (abs3, 0, 0);
  glVertex3d (0, 0, 0);
  glVertex3d (0, dep3, ord3);
  glVertex3d (abs3, dep3, ord3);
  glEnd();

  //left
  x_edge1 = abs1 - 0;
  y_edge1 = dep1 - 0;
  z_edge1 = ord1 - 0;
  x_edge2 = 0;
  y_edge2 = 0 - dep3;
  z_edge2 = 0;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  v3 = v2 ^ v1;
  v3.normalize();
  glBegin(GL_QUADS);
  glNormal3f (v3.x, v3.y, v3.z);
  glVertex3d (abs1, dep1, ord1);
  glVertex3d (abs1, dep2, ord2);
  glVertex3d (0, dep3, ord3);
  glVertex3d (0, 0, 0);
  glEnd();

  //right
  x_edge1 = abs2 - abs3;
  y_edge1 = dep2 - dep3;
  z_edge1 = ord2 - ord3;
  x_edge2 = 0;
  y_edge2 = dep3 - 0;
  z_edge2 = 0;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  v3 = v2 ^ v1;
  v3.normalize();
  glBegin(GL_QUADS);
  glNormal3f (v3.x, v3.y, v3.z);
  glVertex3d (abs3, dep3, ord3);
  glVertex3d (abs2, dep2, ord2);
  glVertex3d (abs2, dep1, ord1);
  glVertex3d (abs3, 0, 0);
  glEnd();

  //back
  x_edge1 = abs2 - abs3;
  y_edge1 = dep2 - dep3;
  z_edge1 = ord2 - ord3;
  x_edge2 = 0 - abs3;
  y_edge2 = 0;
  z_edge2 = 0;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  v3 = v2 ^ v1;
  v3.normalize();
  glBegin(GL_QUADS);
  glNormal3f (v3.x, v3.y, v3.z);
  glVertex3d (0, dep3, ord3);
  glVertex3d (abs1, dep2, ord2);
  glVertex3d (abs2, dep2, ord2);
  glVertex3d (abs3, dep3, ord3);
  glEnd();

  //front
  x_edge1 = abs1 - 0;
  y_edge1 = dep1 - 0;
  z_edge1 = ord1 - 0;
  x_edge2 = abs3 - 0;
  y_edge2 = 0;
  z_edge2 = 0;
  v1.setValue(x_edge1, y_edge1, z_edge1);
  v2.setValue(x_edge2, y_edge2, z_edge2);
  v3 = v2 ^ v1;
  v3.normalize();
  glBegin(GL_QUADS);
  glNormal3f (v3.x, v3.y, v3.z);
  glVertex3d (abs3, 0, 0);
  glVertex3d (abs2, dep1, ord1);
  glVertex3d (abs1, dep1, ord1);
  glVertex3d (0, 0, 0);
  glEnd();
  glEndList();
}
