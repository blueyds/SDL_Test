#include "game.hpp"
#include "SDL_image.h"
#include <iostream>

SDL_Texture *playerTex;
SDL_Rect srcR, destR;

Game::Game(/* args */) {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "Subsystems Initialized..." << std::endl;
    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (window) {
      std::cout << "Window created" << std::endl;
    } else {
      std::cout << "Window Failed" << std::endl;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      std::cout << "Renderer created!" << std::endl;
    }
    isRunning = true;
  } else {
    isRunning = false;
  }

  SDL_Surface *tmpSurface = IMG_Load("./assets/Sara_16x18_Preview.png");
  playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
  SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    /* code */
    isRunning = false;
    break;

  default:
    break;
  }
}
void Game::update() {
  cnt++;
  std::cout << cnt << std::endl;

  destR.h = 64;
  destR.w = 64;
  destR.x = cnt;
}

void Game::render() {
  SDL_RenderClear(renderer);
  // this is where we add stuff to render
  SDL_RenderCopy(renderer, playerTex, NULL, &destR);
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}