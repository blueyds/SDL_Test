#include "TransformComponent.hpp"

ECS::Transformable::Transformable() {
  position = Vector2D();
  velocity = Vector2D();
}

ECS::Transformable::Transformable(float x, float y) {
  position = Vector2D(x, y);
  velocity = Vector2D();
}

ECS::Transformable::Transformable( int sc) {
  position = Vector2D();
  velocity = Vector2D();
  scale = sc;
}

ECS::Transformable::Transformable(float x, float y, int h, int w, int s) {
  position = Vector2D(x, y);
  velocity = Vector2D();
  height = h;
  width = w;
  scale = s;
}


float ECS::Transformable::scaledWidth() { return width * scale; }

float ECS::Transformable::scaledHeight() { return height * scale; }