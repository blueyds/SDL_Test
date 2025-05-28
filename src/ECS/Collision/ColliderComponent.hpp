#ifndef COLLIDER_COMPONENT_HPP_135732
#define COLLIDER_COMPONENT_HPP_135732

#include "Collision.hpp"
#include "Core/Component.hpp"
#include "Core/Entity.hpp"
#include "Drawing/TransformComponent.hpp"

#include <SDL2/SDL.h>
#include <string>

namespace ECS {

class Collider : public Component {

public:
  SDL_Rect collider;
  std::string tag;
  Transformable *transform;
  Collider *colliderTest;
  Entity *testEntity;

  Collider(std::string t, Entity &entityToTestAgainst) {
    tag = t;
    testEntity = &entityToTestAgainst;
  }
  void init() override {
    if (!entity->hasComponent<Transformable>()) {
      entity->addComponent<Transformable>();
    }
    colliderTest = &testEntity->getComponent<Collider>();
    transform = &entity->getComponent<Transformable>();
  }

  void update() override {
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = transform->scaledWidth();
    collider.h = transform->scaledHeight();

    if (Collision::AABB(colliderTest, this)) {
      //   testEntity->getComponent<Transformable>().velocity *= -1;
    };
  }
};
} // namespace ECS
#endif