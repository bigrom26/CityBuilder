#ifndef _VECTOR_
#define _VECTOR_

#include <OpenGL/gl.h>
#include <math.h>


/**
  @brief A vector

  The template should works with float, int, double... (default : float)
*/
template <typename T = float>
class Vector
{
  public :
    T x, y, z;
    /** Default constructor. Value is set to (0,0,0). */
    Vector() : x(0.0), y(0.0), z(0.0) {}
    Vector(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    /** Equal operator. */
    Vector& operator=(const Vector& v)
    {
      x = v.x;   y = v.y;   z = v.z;
      return *this;
    }
    /** Set the current value. May be faster than using operator=() with a temporary Vector(x,y,z). */
    void setValue(T X, T Y, T Z)
    { x=X; y=Y; z=Z; }

    /** @name Algebraic computations */
    //@{
    /*! Returns the sum of the two vectors. */
    friend Vector operator+(const Vector &a, const Vector &b)
    {
      return Vector(a.x+b.x, a.y+b.y, a.z+b.z);
    }

    /*! Returns the difference of the two vectors. */
    friend Vector operator-(const Vector &a, const Vector &b)
    {
      return Vector(a.x-b.x, a.y-b.y, a.z-b.z);
    }

    /*! Returns \c true only when the two vector are not equal (see operator==()). */
    friend bool operator!=(const Vector &a, const Vector &b)
    {
      return !(a==b);
    }

    /*! Returns \c true when the squaredNorm() of the difference vector is lower than 1E-10. */
    friend bool operator==(const Vector &a, const Vector &b)
    {
      const float epsilon = 1.0E-10f;
      return (a-b).squaredNorm() < epsilon;
    }

    /*! Adds \p a to the vector. */
    Vector& operator+=(const Vector &a)
    {
      x += a.x; y += a.y; z += a.z;
      return *this;
    }

    /*! Subtracts \p a to the vector. */
    Vector& operator-=(const Vector &a)
    {
      x -= a.x; y -= a.y; z -= a.z;
      return *this;
    }

    /*! Divides the vector by a scalar \p k */
    Vector& operator/=(float k)
    {
      x /= k; y /= k; z /= k;
      return *this;
    }

    /*! Multiply the vector by a scalar \p k. */
    Vector& operator*=(T k)
    {
      x *= k; y *= k; z *= k;
      return *this;
    }

    /*! Returns the division of the vector with a scalar. */
    friend Vector operator/(const Vector &a, float k)
    {
      return Vector(a.x/k, a.y/k, a.z/k);
    }

    /*! Dot product of the two Vec. */
    friend T operator*(const Vector &a, const Vector &b)
    {
      return a.x*b.x + a.y*b.y + a.z*b.z;
    }

    /*! Cross product of the two vectors. Same as cross(). */
    friend Vector operator^(const Vector &a, const Vector &b)
    {
      return cross(a,b);
    }

    /*! Cross product of the two Vec. Mind the order ! */
    friend Vector cross(const Vector &a, const Vector &b)
    {
      return Vector(a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x);
    }

    /*! Normalizes the Vector and returns its original norm.
    Normalizing a null vector will result in \c NaN values. */
    float normalize()
    {
      const float n = norm();
      *this /= n;
      return n;
    }

    /*! Returns the \e squared norm of the Vec. */
    float squaredNorm() const { return x*x + y*y + z*z; }

    /*! Returns the norm of the vector. */
    float norm() const { return sqrt(x*x + y*y + z*z); }

    /*! A debug oriented draw of the vector
      @param pos Vector position (default value is (0, 0, 0))
    */
    void drawTo(const Vector& pos = Vector(0, 0, 0)) const
    {
      GLboolean lighting;
      glGetBooleanv(GL_LIGHTING, &lighting);
      GLfloat color[4];
      glGetFloatv(GL_CURRENT_COLOR, &color[0]);
      glDisable(GL_LIGHTING);
      glColor3f(1.0, 0.0, 0.0);
      glBegin(GL_LINES);
      glVertex3f(pos.x , pos.y, pos.z);
      glVertex3f(pos.x + x, pos.y + y, pos.z + z);
      glEnd();
      glColor3f(color[0], color[1], color[2]);
      if (lighting)
	glEnable(GL_LIGHTING);
    }

    void drawTo(float x, float y, float z) const
    {
      drawTo(Vector(x, y, z));
    }
};

#endif
