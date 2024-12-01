#include "Entity.hpp"
#include "KeyboardController.hpp"
#include "TransformComponent.hpp"

void ECS::Keyboard::init() {
  transform = &entity->getComponent<ECS::Transformable>();
}

void ECS::Keyboard::update() {
  if (event->type == SDL_KEYDOWN) {
    switch (event->key.keysym.sym) {
    case SDLK_w:
      transform->velocity.y = -1;
      break;
    case SDLK_a:
      transform->velocity.x = -1;
      break;
    case SDLK_d:
      transform->velocity.x = 1;
      break;
    case SDLK_s:
      transform->velocity.y = 1;
      break;
    default:
      break;
    }
  }
  if (event->type == SDL_KEYUP) {
    switch (event->key.keysym.sym) {
    case SDLK_w:
      transform->velocity.y = 0;
      break;
    case SDLK_a:
      transform->velocity.x = 0;
      break;
    case SDLK_d:
      transform->velocity.x = 0;
      break;
    case SDLK_s:
      transform->velocity.y = 0;
      break;
    default:
      break;
    }
  }
};