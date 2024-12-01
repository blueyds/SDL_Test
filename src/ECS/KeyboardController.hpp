#ifndef KEYBOARD_CONTROLLER_H_43389210
#define KEYBOARD_CONTROLLER_H_43389210

#include "TransformComponent.hpp"
#include <SDL.h>

namespace ECS {
class Animation;

class Keyboard : public Component {
public:
  Keyboard(SDL_Event *event) { this->event = event; }

  void init() override;

  void update() override;

private:
  ECS::Transformable *transform;
  ECS::Animation *animate;

  SDL_Event *event;
};
} // namespace ECS
#endif