#include "Playground.hpp"

void Playground::init()
{
  //WARNING nothing before gl initialisation !
  // back face culling
  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  glEnable(GL_NORMALIZE);
  // size of the scene, you can change for a bigger one
  sceneSize = 10;
  setSceneRadius(sceneSize);
  setFPSIsDisplayed();
  setAxisIsDrawn();
  showEntireScene();
  wiremode = false;
  bfc = true; // back-face culling
  grid = true;

  jw1 = new JailWindow();
  jw2 = new JailWindow();
  jw3 = new JailWindow();
  bwww = new BasicWallWithWindow();
  bwww->set(10, 4, 3);
  bwww->fillNeed(jw1, 0);
  bwww->fillNeed(jw2, 1);
  bwww->fillNeed(jw3, 2);
  bwww->build();
}

void Playground::draw()
{
  if(grid)
    // draw a grid (unit = 1 meter)
    drawGrid(sceneSize, sceneSize*2);

  bwww->draw();
}

QString Playground::helpString() const
{
  QString text("<h2>Simple Viewer</h2>"
	       "A simple viewer used for tests and play around.");
  return text;
}

void Playground::keyPressEvent(QKeyEvent *e)
{
  switch(e->key())
  {
    case Qt::Key_G:
      grid = !grid;
      break;
    case Qt::Key_W:
      wiremode = !wiremode;
      if (wiremode)
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      else
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      break;
    case Qt::Key_B:
      bfc = !bfc;
      if(bfc)
        glEnable(GL_CULL_FACE);
      else
        glDisable(GL_CULL_FACE);
      break;
    default:
    /* Call the default handler */
    QGLViewer::keyPressEvent(e);
  }
  /* Update the screen */
  update();
}
