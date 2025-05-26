#ifndef AA3560F9_1506_4808_BE08_5FF69771CB4A
#define AA3560F9_1506_4808_BE08_5FF69771CB4A
#include "ECS/ColliderComponent.hpp"
#include <SDL2/SDL.h>
#include <vector>

class Game {
private:
  /* data */
  bool isRunning;
  int cnt = 0;
  SDL_Window *window;
  SDL_Event event;

public:
  Game(/* args */);
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();
  bool running() { return isRunning; }

  static void addTile(int id, int row, int column);

  static SDL_Renderer *renderer;
};

#endif // AA3560F9_1506_4808_BE08_5FF69771CB4A
