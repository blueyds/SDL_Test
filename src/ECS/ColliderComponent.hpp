#ifndef COLLIDER_COMPONENT_HPP_135732
#define COLLIDER_COMPONENT_HPP_135732

#include <SDL.h>
#include <string>
#include <game.hpp>
#include "ECS.hpp"
#include "TransformComponent.hpp"

namespace ECS {

class Collider : public Component {
public:
  SDL_Rect collider;
  std::string tag;
  Transformable *transform;

  Collider(std::string t) { tag = t; }
  void init() override {
    if (!entity->hasComponent<Transformable>()) {
      entity->addComponent<Transformable>();
    }
    transform = &entity->getComponent<Transformable>();
    Game::colliders.push_back(this);
  }

  void update() override {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = transform->scaledWidth();
    collider.h = transform->scaledHeight();
  }
};
} // namespace ECS
#endif