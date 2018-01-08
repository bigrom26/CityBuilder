#include "HappyCylinder.hpp"

HappyCylinder::HappyCylinder(float r1, float r2, float h, float a, int q)
    : radius1(r1), radius2(r2), height(h), angle(a), quality(q)
{
  if(r1>r2)
  {
    bv = new AABB(h, r1*2, r1*2);
    bv->translateOf(-r1, -r1, 0);
  }
  else
  {
    bv = new AABB(h, r2*2, r2*2);
    bv->translateOf(-r2, -r2, 0);
  }
  build();
}

void HappyCylinder::setQuality(int q)
{
  quality = q;
  rebuild(radius1, radius2, height, angle, quality);
}

void HappyCylinder::rebuild(float r1, float r2, float h, float a, int q)
{
  radius1 = r1;
  radius2 = r2;
  height = h;
  angle = a;
  quality = q;
  build();
}

void HappyCylinder::build() const
{
  glNewList(list, GL_COMPILE);
  float alpha, beta;
  float x, y;
  Vector<float> vertex1, vertex2, normal;
  // shape
  glBegin(GL_QUAD_STRIP);
  for (int i = 0; i <= quality; i++)
  {
    alpha = angle * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    vertex1.setValue(radius1*x, radius1*y, 0);
    vertex2.setValue(radius2*x, radius2*y, height);

    // calculate normal
    beta = angle * (i + 1) / quality;
    Vector<> v1(radius1*cos(beta) - vertex1.x, radius1*sin(beta) - vertex1.y, 0);
    Vector<> v2(vertex2.x - radius1*x, vertex2.y - radius1*y, height);
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
  // for (int i = 0; i <= quality; i++)
  for (int i = quality; i >= 0; i--)
  {
    alpha = angle * i / quality; // version Flavien : -i
    x = cos(alpha);
    y = sin(alpha);
    glNormal3f (0, 0, -1);
    glVertex3d (radius1*x, radius1*y, 0);
  }
  glEnd();
  // top
  glBegin(GL_TRIANGLE_FAN);
  glNormal3f (0, 0, 1);
  glVertex3d (0, 0, height);
  for (int i = 0; i <= quality; i++)
  {
    alpha = angle * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    glNormal3f (0, 0, 1);
    glVertex3d (radius2*x, radius2*y, height);
  }
  glEnd();
  glEndList();
}
