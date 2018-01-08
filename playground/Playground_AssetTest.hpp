#ifndef _VIEWER_
#define _VIEWER_

#include <QKeyEvent>
#include <QGLViewer/qglviewer.h>
#include "../Buildings/Assets/JailWindow.hpp"
#include "../Buildings/Assets/BasicWallWithWindow.hpp"

/** @brief Simple viewer */
class Playground : public QGLViewer
{
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

    JailWindow* jw1;
    JailWindow* jw2;
    JailWindow* jw3;
    BasicWallWithWindow* bwww;
};

#endif
