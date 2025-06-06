#include <iostream>

#include "Collision/ColliderComponent.hpp"
#include "Collision/Collision.hpp"

using namespace ECS;
bool Collision::AABB(const SDL_Rect &recA, const SDL_Rect &recB) {
  if (recA.x + recA.w >= recB.x && recB.x + recB.w >= recA.x &&
      recA.y + recA.h >= recB.y && recB.y + recB.h >= recA.y) {
    return true;
  }
  return false;
}

bool Collision::AABB(const Collider &colA, const Collider &colB) {
  if (AABB(colA.collider, colB.collider)) {
    if (colA.tag == colB.tag) {
      return false;
    }
    std::cout << colA.tag << " hit " << colB.tag << std::endl;
    return true;
  }
  return false;
}

bool Collision::AABB(const Collider *colA, const Collider *colB) {
  if (AABB(colA->collider, colB->collider)) {
    if (colA->tag == colB->tag) {
      return false;
    }
    std::cout << colA->tag << " hit " << colB->tag << std::endl;
    return true;
  }
  return false;
}
