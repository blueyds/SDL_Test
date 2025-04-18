#ifndef VECTOR_2D_HPP_64278
#define VECTOR_2D_HPP_64278
#include <ostream>

class Vector2D {
public:
  float x;
  float y;

  Vector2D();
  Vector2D(float x, float y);

  Vector2D &Add(const Vector2D &vec);
  Vector2D &Subtract(const Vector2D &vec);
  Vector2D &Multiply(const Vector2D &vec);
  Vector2D &Divide(const Vector2D &vec);

  Vector2D &Absolute();

  friend Vector2D &operator+(Vector2D &v1, const Vector2D &v2);
  friend Vector2D &operator-(Vector2D &v1, const Vector2D &v2);
  friend Vector2D &operator*(Vector2D &v1, const Vector2D &v2);
  friend Vector2D &operator/(Vector2D &v1, const Vector2D &v2);

  Vector2D &operator+=(const Vector2D &v2);
  Vector2D &operator-=(const Vector2D &v2);
  Vector2D &operator*=(const Vector2D &v2);
  Vector2D &operator/=(const Vector2D &v2);

  Vector2D &operator*=(const int i);

  Vector2D &Zero();

  friend std::ostream &operator<<(std::ostream &os, const Vector2D &vec);
};

#endif