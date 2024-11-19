#include "game.hpp"

Game *game = nullptr;

int main(int, char **) {
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  uint32_t frameStart;
  int frameTime;
  game = new Game();
  game->init("Craig Game", 0, 0, 800, 600, false);

  while (game->running()) {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();

    frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  };
  game->clean();
  delete (game);
}
