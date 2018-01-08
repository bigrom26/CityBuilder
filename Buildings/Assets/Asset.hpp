#ifndef _ASSET_
#define _ASSET_

#include <vector>
#include <string>
#include <iostream>
#include <OpenGL/gl.h>
#include <Object.hpp>

class Architect;

using std::vector;
using std::string;
/*
enum TYPE {
  //generic type
  BALCONY,
  BOTTOMFLOOR,
  BUILDING,
  BUSSTOP,
  CHIMNEY,
  COLUMN,
  DECORATION,
  DOOR,
  FRAMEDOOR,
  FRAMEWINDOW,
  GUARDRAIL,
  MIDDLEFLOOR,
  ROOF,
  SATELLITEDISH,
  STREETLIGHT,
  TOPFLOOR,
  TRAFFICLIGHT,
  WALL,
  WALLWITHDOOR,
  WALLWITHWINDOW,
  WINDOW,
};*/


// FIXME : faire le syteme de boolean qui va bien !
//ALL = 1111111,
//VICTORIAN = 0000001,
//WESTERN = 0000010,
//...
enum STYLE {
  VICTORIAN,
  ROMAN,
  CLASSIC,
  WESTERN,
};

enum QUALITY {
  LOW,
  MEDIUM,
  HIGHT,
};

/** @brief A generic Asset class */
class Asset
{
  friend class Architect;
  public :
    /** Default constructor */
    Asset(QUALITY q = HIGHT);
    ~Asset();

    void addObject(Object* o);
    void addAsset(Asset* o);

    void draw() const;
    void drawBV() const;
    /** Draw recursively BV */
    void drawBVR(int depth = 1) const;
    BV* getBV() const;
    string getType() const;
    void moveTo(float _x, float _y, float _z);
    void translateOf(float _x, float _y, float _z);
    void rotateOf(float _rx, float _ry, float _rz);
    void changeQuality(QUALITY q);
    void setArchitect(Architect* a);
    virtual void _changeQuality(QUALITY q); //<- can be set in ur asset
  protected :
    float x, y, z;
    float rx, ry, rz;
    STYLE style;
    string type;
    QUALITY quality;
    vector<Object*>* objects;
    vector<Asset*>* assets;
    BV* bv;
    int list;
    Architect* archi;
    void build();
    /** Implement in specialized assets */
    virtual void setBuiltIn() =0;
};

#endif
