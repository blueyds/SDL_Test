#ifndef KEYBOARD_CONTROLLER_H_43389210
#define KEYBOARD_CONTROLLER_H_43389210
#include "ECS.h"
#include <SDL.h>

class KeyboardController : public Component {
public:
  TransformComponent *transform;
  KeyboardController(SDL_Event *event) { this->event = event; }

  void init() override {
    transform = &entity->getComponent<TransformComponent>();
  }
  void update() override {
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

private:
  SDL_Event *event;
};

#endif