#ifndef _CITYVIEWER_
#define _CITYVIEWER_

#include <QGLViewer/qglviewer.h>

/** @brief Main viewer for CityBuilder */
class CityViewer : public QGLViewer
{
  protected :
    void draw();
    void init();
    // void animate();
    /** @brief Set some text in the help window */
    QString helpString() const;
};

#endif
