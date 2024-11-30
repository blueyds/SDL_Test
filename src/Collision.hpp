#ifndef COLLISON_HPP_6739234
#define COLLISON_HPP_6739234
#include <SDL.h>
class ECS::Collider;

class Collision {
public:
  static bool AABB(const SDL_Rect &recA, const SDL_Rect &recB);
  static bool AABB(const ECS::Collider& colA, const ECS::Collider& colB);
};

#endif