#include "game.hpp"
#include "ECS/Collision.hpp"
#include "Map.hpp"
// #include "gameObject.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

#include "ECS/Components.hpp"
#include "player.hpp"

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

  Map::LoadMap("map16x16.map", 16, 16);
  player.addComponent<ECS::Transformable>(0, 0, 64, 48, 1);
  player.addComponent<ECS::Sprite>(
      std::string("universal-lpc-sprite_male_01_walk-3frame.png"));
  player.addComponent<ECS::Animation>(3, 500);
  player.addComponent<ECS::Keyboard>(&event);
  player.addComponent<ECS::Collider>(std::string("player"), player);

  player.addGroup(groupPlayers);

  wall.addComponent<ECS::Transformable>(300.0f, 300.0f, 300, 20, 1);
  wall.addComponent<ECS::Sprite>(std::string("dirt.png"));
  wall.addComponent<ECS::Collider>(std::string("wall"), player);
  wall.addGroup(groupMap);
}
SDL_Event Game::event;
void Game::handleEvents() {
  SDL_PollEvent(&Game::event);
  switch (Game::event.type) {
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
}

void Game::render() {
  SDL_RenderClear(renderer);
  // this is where we add stuff to render
  // map->DrawMap();
  // player->render();
  manager.drawGroup(groupMap);
  manager.drawGroup(groupPlayers);
  manager.drawGroup(groupEnemies);

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}

void Game::addTile(int id, int x, int y) {
  auto &tile(manager.addEntity());
  tile.addComponent<ECS::Tile>(x, y, 32, 32, id);
  tile.addGroup(groupMap);
}