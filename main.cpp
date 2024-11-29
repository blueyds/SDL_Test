#include "game.hpp"
#include <chrono>
#include <thread>

Game *game = nullptr;

uint64_t getTicks() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch())
      .count();
}
int main(int, char **) {
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  uint64_t frameStart;
  int frameTime;

  game = new Game();
  game->init("Craig Game", 0, 0, 800, 640, false);

  while (game->running()) {
    frameStart = getTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = getTicks() - frameStart;
    if (frameDelay > frameTime) {
      std::this_thread::sleep_for(
          std::chrono::milliseconds(frameDelay - frameTime));
      //			SDL_Delay(frameDelay - frameTime);
    }
  };
  game->clean();
  delete (game);
}
