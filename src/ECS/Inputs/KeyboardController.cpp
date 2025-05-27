#include "ECS/Inputs/KeyboardController.hpp"
#include <iostream>
#include <map>
// #include "AnimationComponent.hpp"
// #include "Entity.hpp"

void ECS::Keyboard::registerKeyDown(SDL_Keycode keycode, int action) {
  // TODO: throw an exception ifi action is 0
  keyDownEvents[keycode] = action;
};

void ECS::Keyboard::registerKeyUp(SDL_Keycode keycode, int action) {
  // ToDO: throw an exception if action is 0
  keyUpEvents[keycode] = action;
};

int ECS::Keyboard::popAction() {
  int result = action;
  action = 0;
  return result;
};

void ECS::Keyboard::update() {
  if (!handleKeyDown()) {
    handleKeyUp();
  };
};
bool ECS::Keyboard::handleKeyDown() {
  if (event->type == SDL_KEYDOWN) {
    try {
      action = keyDownEvents.at(event->key.keysym.sym);
    } catch (const std::out_of_range &ex) {
      std::cout << "key not registered" << std::endl;
    }
    return true;
  };
  return false;
};

bool ECS::Keyboard::handleKeyUp() {
  if (event->type == SDL_KEYUP) {
    try {
      action = keyUpEvents.at(event->key.keysym.sym);
    } catch (const std::out_of_range &ex) {
      std::cout << "key not registered" << std::endl;
    }
    return true;
  };
  return false;
};