#ifndef COLLIDER_COMPONENT_HPP_135732
#define COLLIDER_COMPONENT_HPP_135732

#include "ECS.h"
#include <SDL.h>
#include <string>

class ColliderComponent : public Component {
public:
  SDL_Rect collider;
  std::string tag;
  TransformComponent *transform;

  ColliderComponent(std::string t) { tag = t; }
  void init() override {
    if (!entity->hasComponent<TransformComponent>()) {
      entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();
  }

  void update() override {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = transform->scaledWidth();
    collider.h = transform->scaledHeight();
  }
};

#endif