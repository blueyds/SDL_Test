#include "Vector2D.h"

Vector2D::Vector2D() {
  x = 0.0f;
  y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
  this->x = x;
  this->y = y;
}

Vector2D &Vector2D::Add(const Vector2D &vec) {
  x += vec.x;
  y += vec.y;
  return *this;
}

Vector2D &Vector2D::Subtract(const Vector2D &vec) {
  x -= vec.x;
  y -= vec.y;
  return *this;
}

Vector2D &Vector2D::Multiply(const Vector2D &vec) {
  x *= vec.x;
  y *= vec.y;
  return *this;
}

Vector2D &Vector2D::Divide(const Vector2D &vec) {
  x /= vec.x;
  y /= vec.y;
  return *this;
}

Vector2D &operator+(Vector2D &v1, const Vector2D &v2) { return v1.Add(v2); }

Vector2D &operator-(Vector2D &v1, const Vector2D &v2) {
  return v1.Subtract(v2);
}

Vector2D &operator*(Vector2D &v1, const Vector2D &v2) {
  return v1.Multiply(v2);
}

Vector2D &operator/(Vector2D &v1, const Vector2D &v2) { return v1.Divide(v2); }

Vector2D &Vector2D::operator+=(const Vector2D &v2) { return this->Add(v2); }

Vector2D &Vector2D::operator-=(const Vector2D &v2) {
  return this->Subtract(v2);
}

Vector2D &Vector2D::operator*=(const Vector2D &v2) {
  return this->Multiply(v2);
}

Vector2D &Vector2D::operator*=(const int i) {
  this->x *= i;
  this->y *= i;
  return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &v2) { return this->Divide(v2); }

std::ostream &operator<<(std::ostream &os, const Vector2D &vec) {
  os << "(" << vec.x << "," << vec.y << ")";
  return os;
}