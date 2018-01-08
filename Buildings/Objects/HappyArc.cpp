#include "HappyArc.hpp" 

HappyArc::HappyArc(float r, float l, float eps, int q)// rayon, largeur ,epaisseur ,quality
{
  //bv = new BArc(r)?????;
  rebuild(r, l, eps, q);
}

void HappyArc::rebuild(float r, float l, float eps, int q)
{
  radius = r;
  largeur = l;
  epaisseur = eps;
  quality=q;
  build();
}

void HappyArc::build() const
{
  glNewList(list, GL_COMPILE);
  float alpha;
  float x, y;

  //construction de l'epaisseur de l'arc

  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i <= quality; i++)
  {
    alpha = M_PI * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    glNormal3f (0, -1, 0);
    glVertex3d (radius*x, 0, radius*y);
    glVertex3d ((radius+epaisseur)*x, 0, (radius+epaisseur)*y);
  }
  glEnd();

  //construction de la largeur de l'arc

  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i <= quality; i++)
  {
    alpha =  M_PI * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    glNormal3f (0, 1, 0);
    glVertex3d ((radius+epaisseur)*x, largeur, (radius+epaisseur)*y);
    glVertex3d (radius*x, largeur, radius*y);
  }
  glEnd();

  //partie milieu 1
  float beta;
  Vector<> v1, v2, normal;
  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i <= quality; i++)
  {
    alpha =  M_PI * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    beta = M_PI * ( i + 1 ) / quality;
    v1.setValue((radius+epaisseur)*cos(beta) - (radius+epaisseur)*cos(alpha), 0, (radius+epaisseur)*sin(beta) - (radius+epaisseur)*sin(alpha));
    v2.setValue(0, -largeur, 0);
    normal = v1 ^ v2;
    normal.normalize();
    glNormal3f (normal.x, normal.y, normal.z);
    glVertex3d ((radius+epaisseur)*x, 0, (radius+epaisseur)*y);
    glVertex3d ((radius+epaisseur)*x, largeur, (radius+epaisseur)*y);
  }
  glEnd();

  //partie milieu 2

  glBegin(GL_TRIANGLE_STRIP);
  for (int i = 0; i <= quality; i++)
  {
    alpha =  M_PI * i / quality;
    x = cos(alpha);
    y = sin(alpha);
    beta = M_PI * ( i + 1 ) / quality;
    v1.setValue(radius*cos(beta) - radius*cos(alpha), 0, radius*sin(beta) - radius*sin(alpha));
    v2.setValue(0, -largeur, 0);
    normal = v2 ^ v1;
    normal.normalize();
    glNormal3f (normal.x, normal.y, normal.z);
    glVertex3d (radius*x, largeur, radius*y);
    glVertex3d (radius*x, 0, radius*y);
  }
  glEnd();
  
  //extremite droite de l'arc

  glBegin(GL_QUADS);
  glNormal3f(0, 0, -1);
  glVertex3d (radius,largeur,0);
  glVertex3d (radius+epaisseur,largeur,0);
  glVertex3d (radius+epaisseur,0,0);
  glVertex3d (radius, 0, 0);
  glEnd();

  //extremite gauche de l'arc

  glBegin(GL_QUADS);
  glNormal3f(0, 0, -1);
  glVertex3d (-radius, 0, 0);
  glVertex3d (-(radius+epaisseur),0,0);
  glVertex3d (-(radius+epaisseur),largeur,0);
  glVertex3d (-radius,largeur,0);
  glEnd();

  glEndList();
}
 
