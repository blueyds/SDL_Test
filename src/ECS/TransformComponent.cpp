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

void ECS::Transformable::moveUp(float speed){
  velocity = Vector2D(0,-1 * speed);
}

void ECS::Transformable::moveDown(float speed){
  velocity = Vector2D(0,speed);
}

void ECS::Transformable::moveLeft(float speed){
  velocity = Vector2D(-1 * speed, 0);
}

void ECS::Transformable::moveRight(float speed){
  velocity = Vector2D(speed, 0);
}

void ECS::Transformable::stop(){
  velocity = Vector2D(0,0);
}

float ECS::Transformable::scaledWidth() { return width * scale; }

float ECS::Transformable::scaledHeight() { return height * scale; }