#include "Viewer/CityViewer.hpp"
#include <qapplication.h>

int main(int argc, char** argv)
{
  // Read command lines arguments.
  QApplication application(argc,argv);
  CityViewer cv;
  cv.setWindowTitle("City Builder");
  cv.show();
  return application.exec();
}