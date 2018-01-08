#ifndef _BV_
#define _BV_

#include <OpenGL/gl.h>
#include <math.h>

/** @brief An abstract class for bounding volumes */
class BV
{
  public :
    /** @brief Constructor */
    BV();
    /** @brief Draw BV's shape in a debug oriented wiremode
      Set light, color and call paintGL().
    */
    void draw() const;
    /** @brief Change position */
    void moveTo(float _x, float _y, float _z);
    void translateOf(float _x, float _y, float _z);
    void rotateOf(float _rx, float _ry, float _rz);
    float getX() const;
    float getY() const;
  protected :
    /** @brief Paint the shape
      Must include GL's painting functions
    */
    virtual void paintGL() const =0;
    float x, y, z;
    float rx, ry, rz;
};

#endif
