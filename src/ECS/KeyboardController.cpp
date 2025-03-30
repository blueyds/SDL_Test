#include <map>
#include <iostream>
#include "KeyboardController.hpp"
//#include "AnimationComponent.hpp"
//#include "Entity.hpp"

void ECS::Keyboard::registerKeyDown(SDL_Keycode keycode, int action){
  // TODO: throw an exception ifi action is 0
  keyDownEvents[keycode] = action;
};

void ECS::Keyboard::registerKeyUp(SDL_Keycode keycode, int action){
  // ToDO: throw an exception if action is 0
  keyUpEvents[keycode] = action;
};

int ECS::Keyboard::popAction(){
  int result = action;
  action = 0;
  return result;
};

void ECS::Keyboard::update(){
  if (!handleKeyDown()){
    handleKeyUp();
  };
};
bool ECS::Keyboard::handleKeyDown(){
  if (event->type == SDL_KEYDOWN){
    try{
      action = keyDownEvents.at(event->key.keysym.sym);
    } 
    catch(const std::out_of_range& ex) {
      std::cout << "key not registered" << std::endl;
    }
    return true;
  };
  return false;
};


bool ECS::Keyboard::handleKeyUp(){
  if (event->type == SDL_KEYUP){
    try{
      action = keyUpEvents.at(event->key.keysym.sym);
    } 
    catch(const std::out_of_range& ex) {
      std::cout << "key not registered" << std::endl;
    }
    return true;
  };
  return false;
};
/*
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
*/