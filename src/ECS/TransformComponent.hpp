#ifndef TRANSFORM_COMPONENT_HPP_1234351223
#define TRANSFORM_COMPONENT_HPP_1234351223

#include "ECS.h"
#include <Vector2D.hpp>

namespace ECS {
class Transformable : public Component {
public:
  Vector2D position;
  Vector2D velocity;
  int height = 32;
  int width = 32;
  int scale = 1;
  int speed = 3;

  Transformable() {
    position = Vector2D();
    velocity = Vector2D();
  }

  Transformable(float x, float y) {
    position = Vector2D(x, y);
    velocity = Vector2D();
  }

  Transformable(int sc) {
    position = Vector2D();
    velocity = Vector2D();
    scale = sc;
  }

  Transformable(float x, float y, int h, int w, int s) {
    position = Vector2D(x, y);
    velocity = Vector2D();
    height = h;
    width = w;
    scale = s;
  }

  void update() override {
    position.x += velocity.x * speed;
    position.y += velocity.y * speed;
  }

  float scaledWidth() { return width * scale; }

  float scaledHeight() { return height * scale; }
};
} // namespace ECS

#endif