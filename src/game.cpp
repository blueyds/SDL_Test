#include "game.hpp"
#include "Collision.hpp"
#include "Map.hpp"
#include "gameObject.hpp"
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

#include "ECS/Components.hpp"

// GameObject *player;
Map *map;

ECS::Manager manager;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());

std::string mapFile("tileset.png");

enum groupLabels : std::size_t {
  groupMap,
  groupPlayers,
  groupEnemies,
  groupColliders
};
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

  player.addComponent<ECS::Transformable>(400,320, 64, 48, 1);
  player.addComponent<ECS::Sprite>(
      std::string("universal-lpc-sprite_male_01_walk-3frame.png"));
  player.addComponent<ECS::Animation>(3, 500);
  player.addComponent<ECS::Keyboard>(&event);
  player.addComponent<ECS::Collider>(std::string("player"), player);

  player.addGroup(groupPlayers);


  Map::LoadMap("map.csv",30,30);

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

void Game::addTile(int srcX, int srcY, int xpos, int ypos) {
  auto &tile(manager.addEntity());
  // ERROR player has not been created when tiles are created. this results in null and segment fault
  ECS::Transformable* pTrans = &player.getComponent<ECS::Transformable>();
  tile.addComponent<ECS::Tile>(srcX, srcY, xpos, ypos, mapFile, pTrans);
  
  tile.addGroup(groupMap);
}