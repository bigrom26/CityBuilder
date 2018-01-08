#ifndef _OBJECT_
#define _OBJECT_

#include <OpenGL/gl.h>
#include <math.h>
#include <Vector.hpp>
#include <BV.hpp>

/** @brief An abstract class for objects */
class Object
{
  public :
    Object();
    ~Object();
    void draw() const;
    void drawBV() const;
    /** @brief Move the object at */
    void moveTo(float _x, float _y, float _z);
    /** @brief Translate the object */
    void translateOf(float _x, float _y, float _z);
    /** @brief Rotate the object */
    void rotateOf(float _rx, float _ry, float _rz);
    BV* getBV() const;
    /** @brief Set alpha transparency */
    void setTransparency(float a);
    /** @brief if disable, object will not be draw */
    void enable();
    void disable();
    void toogle();
    bool isEnable() const;
    virtual void setQuality(int){}; // not necessarly existe;
  protected :
    virtual void build() const =0;
    float x, y, z;
    float rx, ry, rz;
    int list;
    BV* bv;
    float alpha;
    bool _enable;
};

#endif
