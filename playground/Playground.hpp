#ifndef _VIEWER_
#define _VIEWER_




#include <QKeyEvent>
#include <../QGLViewer/qglviewer.h>
#include <Architect.hpp>
#include <Tile_North_South.hpp>
#include <Crossroads.hpp>

/** @brief Simple viewer */
class Playground : public QGLViewer
{
  public :
    //~Playground();
  protected :
    
    void draw();
    void init();
    void keyPressEvent(QKeyEvent *e);
    // void animate();
    /** @brief Set some text in the help window */
    QString helpString() const;
    int sceneSize;
    bool bfc;
    bool wiremode;
    bool grid;
    bool occlusion;
    Architect* a;
      
    //std::vector<BasicBuilding*>* bb;
    
    Crossroads* c;
    Tile_North_South* t;
};

#endif
