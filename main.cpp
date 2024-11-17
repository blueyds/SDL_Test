#include "game.hpp"

Game *game = nullptr;

int main(int, char **) {
  game = new Game();
  game->init("Craig Game", 0, 0, 800, 600, false);
  while (game->running()) {
    game->handleEvents();
    game->update();
    game->render();
  };
  game->clean();
  delete (game);
}
