#include "Playground.hpp"
#include <qapplication.h>

int main(int argc, char** argv)
{
  // Read command lines arguments.
  QApplication application(argc,argv);
  Playground p;
  p.setWindowTitle("Playground");
  p.show();
  return application.exec();
}
