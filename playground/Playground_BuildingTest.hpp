#ifndef _VIEWER_
#define _VIEWER_

#include <QKeyEvent>
#include <QGLViewer/qglviewer.h>
#include "../Buildings/Assets/Building/BasicBuilding.hpp"

/* POUR TESTER
A AJOUTER DANS ARCHITECT.HPP :

#include "../Buildings/Assets/DoorWithHole.hpp"
#include "../Buildings/Assets/SimpleColumn.hpp"
#include "../Buildings/Assets/CrossWindow.hpp"
#include "../Buildings/Assets/FrameDoorWithTriangle.hpp"
#include "../Buildings/Assets/BasicFrameWindow.hpp"
#include "../Buildings/Assets/GuardrailWithColumn.hpp"
#include "../Buildings/Assets/BasicWallWithDoor.hpp"
#include "../Buildings/Assets/BasicWallWithWindow2.hpp"
#include "../Buildings/Assets/BasicBottomFloor.hpp"
#include "../Buildings/Assets/BasicMiddleFloor.hpp"
#include "../Buildings/Assets/BasicTopFloor.hpp"
#include "../Buildings/Assets/SimpleBalcony.hpp"
#include "../Buildings/Assets/SimpleRoof.hpp"
#include "../Buildings/Assets/BasicBuilding.hpp"
#include "../Buildings/Assets/BasicWall.hpp"
#include "../Buildings/Assets/Bar.hpp"


A AJOUTER DANS ARCHITECTE.CPP (fonction get()) :

switch(t) {
    case DOOR :
      return dynamic_cast<Asset*>(dynamic_cast<Door*>(new DoorWithHole()));
	case COLUMN :
      return dynamic_cast<Asset*>(dynamic_cast<Column*>(new SimpleColumn()));
	case WINDOW :
      return dynamic_cast<Asset*>(dynamic_cast<Window*>(new CrossWindow()));
	case WALLWITHDOOR :
      return dynamic_cast<Asset*>(dynamic_cast<WallWithDoor*>(new BasicWallWithDoor()));
	case WALLWITHWINDOW :
      return dynamic_cast<Asset*>(dynamic_cast<WallWithWindow*>(new BasicWallWithWindow2()));
	case FRAMEDOOR :
      return dynamic_cast<Asset*>(dynamic_cast<FrameDoor*>(new FrameDoorWithTriangle()));
	case FRAMEWINDOW :
      return dynamic_cast<Asset*>(dynamic_cast<FrameWindow*>(new BasicFrameWindow()));
	case GUARDRAIL :
      return dynamic_cast<Asset*>(dynamic_cast<Guardrail*>(new GuardrailWithColumn()));
	case BOTTOMFLOOR :
      return dynamic_cast<Asset*>(dynamic_cast<BottomFloor*>(new BasicBottomFloor()));
	case MIDDLEFLOOR :
      return dynamic_cast<Asset*>(dynamic_cast<MiddleFloor*>(new BasicMiddleFloor()));
	case TOPFLOOR :
      return dynamic_cast<Asset*>(dynamic_cast<TopFloor*>(new BasicTopFloor()));
	case BALCONY :
      return dynamic_cast<Asset*>(dynamic_cast<Balcony*>(new SimpleBalcony()));
	case ROOF :
      return dynamic_cast<Asset*>(dynamic_cast<Roof*>(new SimpleRoof()));
	case BUILDING :
      return dynamic_cast<Asset*>(dynamic_cast<Building*>(new BasicBuilding()));
	case WALL :
      return dynamic_cast<Asset*>(dynamic_cast<Wall*>(new BasicWall()));
	case DECORATION :
      return dynamic_cast<Asset*>(dynamic_cast<Decoration*>(new Bar()));
    default :
      return NULL;
  }
  return NULL;

*/
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

	BasicBuilding* bb;
};

#endif
