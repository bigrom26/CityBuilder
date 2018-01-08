#include "Cone.hpp"

Cone::Cone(float r, float h, int q)
    : radius(r), height(h), quality(q)
{
  bv = new AABB(r*2, r*2, h);
  bv->translateOf(-r, -r, 0);
  build();
}

void Cone::rebuild(float r, float h, int q)
{
  radius = r;
  height = h;
  quality = q;
  build();
}

void Cone::build() const
{
  glNewList(list, GL_COMPILE);
  float alpha, beta;
  float x, y;
  Vector<> vertex1, vertex2, normal;
  vertex2.setValue(0, 0, height);
  // shape
  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i <= quality; i++)
  {
    alpha = 2 * M_PI * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    vertex1.setValue(radius*x, radius*y, 0);
    // calculate normal
    beta = 2 * M_PI * (i + 1) / quality;
    Vector<> v1(radius*cos(beta) - vertex1.x, radius*sin(beta) - vertex1.y, 0);
    Vector<> v2(vertex2.x - radius*x, vertex2.y - radius*y, height);
    normal = v1 ^ v2;
    normal.normalize();
    // gl
    glNormal3f (normal.x, normal.y, normal.z);
    glVertex3d (vertex2.x, vertex2.y, vertex2.z);
    glVertex3d (vertex1.x, vertex1.y, vertex1.z);
  }
  glEnd();
  // bottom
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f (0, 0, -1);
  glVertex3d (0, 0, 0);
  for (int i = 0; i <= quality; i++)
  {
    alpha = 2 * M_PI * -i / quality;
    x = cos(alpha);
    y = sin(alpha);
    glNormal3f (0, 0, -1);
    glVertex3d (radius*x, radius*y, 0);
  }
  glEnd();
  glEndList();
}
