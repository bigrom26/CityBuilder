# Uncomment/Comment includes you want to play with
## Don't forget to "make clean" before compiling the playground (to avoid vtable errors)
include("../Buildings/BoundingVolumes/BVs.pro")
include("../Buildings/Objects/Objects.pro")
include("../Buildings/Assets/Assets.pro")

TARGET   = playground

# BVs
DIR_BV = ../Buildings/BoundingVolumes/
for(BV_HEADER_FILE, BV_HEADER_FILES) {
    HEADERS += $$DIR_BV$$BV_HEADER_FILE }
for(BV_SRC_FILE, BV_SRC_FILES) {
    SOURCES += $$DIR_BV$$BV_SRC_FILE }

# Objects
DIR_OBJ = ../Buildings/Objects/
for(OBJ_HEADER_FILE, OBJ_HEADER_FILES) {
    HEADERS += $$DIR_OBJ$$OBJ_HEADER_FILE }
for(OBJ_SRC_FILE, OBJ_SRC_FILES) {
    SOURCES += $$DIR_OBJ$$OBJ_SRC_FILE }

# Assets
DIR_ASSET = ../Buildings/Assets/
for(ASSET_HEADER_FILE, ASSET_HEADER_FILES) {
    HEADERS += $$DIR_ASSET$$ASSET_HEADER_FILE }
for(ASSET_SRC_FILE, ASSET_SRC_FILES) {
    SOURCES += $$DIR_ASSET$$ASSET_SRC_FILE }
for(ASSET, ASSETS) {
    INCLUDEPATH += $$DIR_ASSET/$$ASSET }

INCLUDEPATH += $$DIR_BV $$DIR_OBJ $$DIR_ASSET ../Architect/ ../ToolBox/ ../QGLViewer

HEADERS += glew.h  wglew.h Playground.hpp ../Architect/Architect.hpp ../ToolBox/Factory.hpp ../ToolBox/PlanParser.hpp
SOURCES += main.cpp Playground.cpp ../Architect/Architect.cpp ../ToolBox/Factory.cpp ../ToolBox/PlanParser.cpp
OBJECTS_DIR = ../obj

include(compile.pri)
