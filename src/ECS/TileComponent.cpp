#include "TileComponent.hpp"
#include "Entity.hpp"
#include "SpriteComponent.hpp"

ECS::Tile::Tile(int x, int y, int w, int h, int id) {
  tileRect.x = x;
  tileRect.y = y;
  tileRect.w = w;
  tileRect.h = h;
  tileID = id;
  switch (tileID) {
  case 0:
    path = "water.png";
    break;
  case 1:
    path = "dirt.png";
    break;
  case 2:
    path = "grass.png";
    break;
  default:
    break;
  }
}

void ECS::Tile::init() {
  float x = static_cast<float>(tileRect.x);
  float y = static_cast<float>(tileRect.y);
  entity->addComponent<ECS::Transformable>(x, y, tileRect.w, tileRect.h, 1);
  transform = &entity->getComponent<ECS::Transformable>();
  entity->addComponent<ECS::Sprite>(path);
  sprite = &entity->getComponent<ECS::Sprite>();
}
