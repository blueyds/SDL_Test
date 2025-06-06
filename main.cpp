#include "RpgGame.hpp"
#include "SDL2/SDL_filesystem.h"
#include "SDL2/SDL_main.h"
#include <Utilities.hpp>
#include <chrono>
#include <iostream>
#include <thread>

int main(int, char **) {
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  uint64_t frameStart;
  int frameTime;

  RpgGame game;
  game.init("Craig Game", 0, 0, 800, 640, false);
  char *path = SDL_GetBasePath();
  std::cout << "BASE PATH" << std::string(path) << std::endl;
  std::cout << "Game Start " << Utilities::getTicks() << std::endl;
  while (game.running()) {
    frameStart = Utilities::getTicks();

    game.handleEvents();
    game.update();
    game.render();

    frameTime = Utilities::getTicks() - frameStart;
    if (frameDelay > frameTime) {
      std::this_thread::sleep_for(
          std::chrono::milliseconds(frameDelay - frameTime));
      //			SDL_Delay(frameDelay - frameTime);
    }
  };

  std::cout << "Game End " << Utilities::getTicks() << std::endl;
  game.clean();
}
