#include "BSphere.hpp"

BSphere::BSphere(float r)
  : radius(r)
{
  ;
}

void BSphere::paintGL() const
{
  int quality = 8;
  float theta, phi;
  float x, y, z;
  for (int i = 0; i <= quality; i++)
  {
    glBegin(GL_LINES);
    for (int j = 0; j <= quality; j++)
    {
      phi = 2 * M_PI * j / quality;
      theta = -M_PI/2 + M_PI * (i+1) / quality;
      x = cos(theta) * cos(phi);
      y = cos(theta) * sin(phi);
      z = sin(theta);
      glVertex3d (radius*x, radius*y, radius*z);
      /*--------------------------------------*/
      theta = -M_PI/2 + M_PI * i / quality;
      x = cos(theta) * cos(phi);
      y = cos(theta) * sin(phi);
      z = sin(theta);
      glVertex3d (radius*x, radius*y, radius*z);
    }
    glEnd();
  }
  for (int i = 1; i <= quality; i++)
  {
    glBegin(GL_LINES);
    phi = -M_PI/2 + M_PI * (i) / quality;
    for (int j = 0; j <= quality; j++)
    {
      theta = 2 * M_PI * j / quality;
      x = cos(phi) * cos(theta);
      y = cos(phi) * sin(theta);
      z = sin(phi);
      glVertex3d (radius*x, radius*y, radius*z);
      /*--------------------------------------*/
      theta = 2 * M_PI * (j+1) / quality;
      x = cos(phi) * cos(theta);
      y = cos(phi) * sin(theta);
      z = sin(phi);
      glVertex3d (radius*x, radius*y, radius*z);
    }
    glEnd();
  }
}
