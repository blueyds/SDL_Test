#ifndef TRANSFORM_COMPONENT_HPP_1234351223
#define TRANSFORM_COMPONENT_HPP_1234351223

#include "ECS/Core/Component.hpp"
#include "Vector2D.hpp"

namespace ECS {
class Transformable : public Component {
public:
  Vector2D position;
  Vector2D velocity;
  int height = 32;
  int width = 32;
  int scale = 1;
  // int speed = 3;

  Transformable();

  Transformable(float x, float y);

  Transformable(int sc);

  Transformable(float x, float y, int h, int w, int s);

  float scaledWidth();

  float scaledHeight();

  void moveUp(float speed);
  void moveDown(float speed);
  void moveLeft(float speed);
  void moveRight(float speed);
  void stop();
};
} // namespace ECS

#endif