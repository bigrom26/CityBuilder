# Ce fichier genere le Makefile principal de l'application.
# On pensera a include() les .pro des sous repertoirs

TARGET   = citybuilder
VERSION  = 0.0.1

HEADERS += Viewer/CityViewer.hpp
SOURCES += main.cpp Viewer/CityViewer.cpp
OBJECTS_DIR = ./obj

CONFIG 	+= qt opengl
CONFIG  -= debug warm_on
QT	+= xml opengl

# specifications pour unix
unix {
  LIBS += -lQGLViewer
}
# specifications pour windows
win32 {
  LIBS += QGLViewer225.lib
}

include("Buildings/BoundingVolumes/BVs.pro")
include("Buildings/Objects/Objects.pro")
include("Buildings/Assets/Assets.pro")

# BVs
DIR_BV = Buildings/BoundingVolumes/
for(BV_HEADER_FILE, BV_HEADER_FILES) {
    HEADERS += $$DIR_BV$$BV_HEADER_FILE }
for(BV_SRC_FILE, BV_SRC_FILES) {
    SOURCES += $$DIR_BV$$BV_SRC_FILE }

# Objects
DIR_OBJ = Buildings/Objects/
for(OBJ_HEADER_FILE, OBJ_HEADER_FILES) {
    HEADERS += $$DIR_OBJ$$OBJ_HEADER_FILE }
for(OBJ_SRC_FILE, OBJ_SRC_FILES) {
    SOURCES += $$DIR_OBJ$$OBJ_SRC_FILE }

# Assets
DIR_ASSET = Buildings/Assets/
for(ASSET_HEADER_FILE, ASSET_HEADER_FILES) {
    HEADERS += $$DIR_ASSET$$ASSET_HEADER_FILE }
for(ASSET_SRC_FILE, ASSET_SRC_FILES) {
    SOURCES += $$DIR_ASSET$$ASSET_SRC_FILE }
