#ifndef KEYBOARD_CONTROLLER_H_43389210
#define KEYBOARD_CONTROLLER_H_43389210

#include <SDL2/SDL.h>
#include <map>
#include "Component.hpp"

namespace ECS {

class Keyboard : public Component {
public:
  Keyboard(SDL_Event *event) { this->event = event; }

  
  //void init() override;

  void update() override;
  void registerKeyDown(SDL_Keycode keycode, int action);
  void registerKeyUp(SDL_Keycode keycode, int action);
  int popAction();
private:
  int action = 0;
  bool handleKeyDown();
  bool handleKeyUp();
  std::map<SDL_Keycode,int> keyDownEvents;
  std::map<SDL_Keycode,int> keyUpEvents;

  SDL_Event *event;
};
} // namespace ECS
#endif