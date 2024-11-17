#ifndef AA3560F9_1506_4808_BE08_5FF69771CB4A
#define AA3560F9_1506_4808_BE08_5FF69771CB4A
#include <SDL2/SDL.h>

class Game {
private:
  /* data */
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;

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
};

#endif // AA3560F9_1506_4808_BE08_5FF69771CB4A
