#include "game.hpp"
#include <Utilities.hpp>
#include <chrono>
#include <thread>

Game *game = nullptr;

int main(int, char **) {
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  uint64_t frameStart;
  int frameTime;

  game = new Game();
  game->init("Craig Game", 0, 0, 800, 640, false);

  while (game->running()) {
    frameStart = Utilities::getTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = Utilities::getTicks() - frameStart;
    if (frameDelay > frameTime) {
      std::this_thread::sleep_for(
          std::chrono::milliseconds(frameDelay - frameTime));
      //			SDL_Delay(frameDelay - frameTime);
    }
  };
  game->clean();
  delete (game);
}
