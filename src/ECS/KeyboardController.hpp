#ifndef KEYBOARD_CONTROLLER_H_43389210
#define KEYBOARD_CONTROLLER_H_43389210

#include <SDL.h>

namespace ECS {
class Transformable;
class Keyboard : public Component {
public:
  Keyboard(SDL_Event *event) { this->event = event; }

  void init() override;

  void update() override;

private:
  ECS::Transformable *transform;

  SDL_Event *event;
};
} // namespace ECS
#endif