#include "Sphere.hpp" 

Sphere::Sphere(float r, int q)
  : radius(r), quality(q)
{
  bv = new BSphere(r);
  build();
}

void Sphere::rebuild(float r, int q)
{
  radius = r;
  quality = q;
  build();
}

void Sphere::build() const
{
  glNewList(list, GL_COMPILE);
  float theta, phi;
  float x, y, z;
  for (int i = 0; i <= quality; i++)
  {
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= quality; j++)
    {
      phi = 2 * M_PI * j / quality;
      theta = -M_PI/2 + M_PI * (i+1) / quality;
      x = cos(theta) * cos(phi);
      y = cos(theta) * sin(phi);
      z = sin(theta);
      glNormal3f(x,y,z);
      glVertex3d (radius*x, radius*y, radius*z);
      /*--------------------------------------*/
      theta = -M_PI/2 + M_PI * i / quality;
      x = cos(theta) * cos(phi);
      y = cos(theta) * sin(phi);
      z = sin(theta);
      glNormal3f(x,y,z);
      glVertex3d (radius*x, radius*y, radius*z);
    }
    glEnd();
  }
  glEndList();
}
