#include <iostream>

#include "Collision.h"
#include "Map.h"
#include "SDL_image.h"
#include "game.hpp"
#include "gameObject.hpp"

#include "ECS/Components.h"

// GameObject *player;
Map *map;

ECS::Manager manager;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());
Game::Game(/* args */) {}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;

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
    Game::renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer) {
      SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      std::cout << "Renderer created!" << std::endl;
    }
    isRunning = true;
  } else {
    isRunning = false;
  }
  // player = new GameObject("Sara_16x18_Preview.png", 0, 0);
  map = new Map();
  player.addComponent<ECS::Transformable>(2);
  player.addComponent<ECS::Sprite>("Sara_16x18_Preview.png");
  player.addComponent<ECS::Keyboard>(&event);

  player.addComponent<ECS::Collider>("player");

  wall.addComponent<ECS::Transformable>(300.0f, 300.0f, 300, 20, 1);
  wall.addComponent<ECS::Sprite>("dirt.png");
  wall.addComponent<ECS::Collider>("wall");
}

void Game::handleEvents() {
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::update() {
  // player->update();
  manager.refresh();
  manager.update();
  std::cout << player.getComponent<ECS::Transformable>().position << std::endl;
  if (Collision::AABB(player.getComponent<ECS::Collider>().collider,
                      wall.getComponent<ECS::Collider>().collider)) {
    std::cout << "Wall hit" << std::endl;
    player.getComponent<ECS::Transformable>().velocity *= -1;
  }
}

void Game::render() {
  SDL_RenderClear(renderer);
  // this is where we add stuff to render
  map->DrawMap();
  // player->render();
  manager.draw();
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}
