#ifdef __APPLE__
#else
    #include <glew.h>
#endif

#include "Playground.hpp"

void Playground::init()
{
  //WARNING nothing before gl initialisation !
  // back face culling
#ifndef __APPLE__
    glewInit();
#endif

  glCullFace(GL_BACK);
  glEnable(GL_CULL_FACE);
  // set up for transparency
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // size of the scene, you can change for a bigger one
  sceneSize = 50;
  setSceneRadius(sceneSize);
  setFPSIsDisplayed();
  setAxisIsDrawn();
  showEntireScene();
  wiremode = false;
  bfc = true; // back-face culling
  grid = true;

//---User section---//
  a = new Architect();

  a->workWithPlan("../Buildings/Assets/Tile/BusinessDistrict.xml");
  c = new Crossroads();
  t= new Tile_North_South();
  c->setArchitect(a);
  t->setArchitect(a);
  c->set();
  t->set();
//-----------------//

//New init for the occlusion culling
//  if (GLEW_ARB_occlusion_query)
//  //{
  //Occlusion query is supported on this hardware
    occlusion = true;
  //}
  //else
   //{
  //    occlusion = false;
  //    printf("Hardware do NOT support ARB Occlusion Qierying... It will be laggy...\n");
  // }


}

void Playground::draw()
{
 int buildingCount = 0;
  GLuint queries[1];
  GLuint sampleCount;
  GLint available;
  int ioccl;
  // light
  float pos[4] = {0, 0, 100, 1};
  // Directionnal light
  glLightfv(GL_LIGHT0, GL_POSITION, pos);
  drawLight(GL_LIGHT0);

  if(grid)
    // draw a grid (unit = 1 meter)
    drawGrid(sceneSize, sceneSize*2);

  if(occlusion)
  {
    //glGenQueriesARB(bb->size(), queries);
    glGenQueriesARB(1, queries);
    // before this point, render major occluders
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glDepthMask(GL_FALSE);
    for (ioccl = 0; ioccl < 1; ioccl++) {
	glBeginQueryARB(GL_SAMPLES_PASSED_ARB, queries[ioccl]);
	c->drawBVR(1);//drawBVR draw to much bv, so to much query slow tio much the rendrering sequence
	glEndQueryARB(GL_SAMPLES_PASSED_ARB);
    }

    glFlush();

    ioccl = 1*3/4; // instead of N-1, to prevent the GPU from going idle
    do {
	glGetQueryObjectivARB(queries[ioccl],
			      GL_QUERY_RESULT_AVAILABLE_ARB,
			      &available);
    } while (!available);

    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glDepthMask(GL_TRUE);

    for (ioccl = 0; ioccl < 1; ioccl++) {
	glGetQueryObjectuivARB(queries[ioccl], GL_QUERY_RESULT_ARB,
				&sampleCount);
	if (sampleCount > 100) //Can be used as parameter to display only real visible buildings
	{
	    buildingCount++;
	   // c->draw();
        t->draw();
	}
    }
    //printf("Occlusion rendering  :  ");
  }
  else
  {
    for(int i=0;i<1;i++)
    {
	buildingCount++;
	//c->draw();
        t->draw();
    }
    //printf("Simple rendering  :  ");
  }



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
