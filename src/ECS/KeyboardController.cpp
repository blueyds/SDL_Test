#include "KeyboardController.hpp"
#include "AnimationComponent.hpp"
#include "Entity.hpp"

void ECS::Keyboard::init() {
  transform = &entity->getComponent<ECS::Transformable>();
  animate = &entity->getComponent<ECS::Animation>();
}

void ECS::Keyboard::update() {
  if (event->type == SDL_KEYDOWN) {
    switch (event->key.keysym.sym) {
    case SDLK_w:
      transform->velocity.y = -1;
      animate->play(0);
      break;
    case SDLK_a:
      transform->velocity.x = -1;
      animate->play(3);
      break;
    case SDLK_d:
      transform->velocity.x = 1;
      animate->play(1);
      break;
    case SDLK_s:
      transform->velocity.y = 1;
      animate->play(2);
      break;
    default:
      break;
    }
  }
  if (event->type == SDL_KEYUP) {
    switch (event->key.keysym.sym) {
    case SDLK_w:
      transform->velocity.y = 0;
      animate->stop();
      break;
    case SDLK_a:
      transform->velocity.x = 0;
      animate->stop();
      break;
    case SDLK_d:
      transform->velocity.x = 0;
      animate->stop();
      break;
    case SDLK_s:
      transform->velocity.y = 0;
      animate->stop();
      break;
    default:
      break;
    }
  }
};