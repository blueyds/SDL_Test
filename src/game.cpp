#include "game.hpp"
#include "ECS/Collision.hpp"
#include "Map.hpp"
// #include "gameObject.hpp"
#include "ECS/Components.hpp"
#include "Utilities.hpp"
#include "player.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

// GameObject *player;
Map *map;

ECS::Manager manager;
auto &player(manager.addEntity());
auto &wall(manager.addEntity());

Game::Game(/* args */) {}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;

constexpr int PLAYER_MOVE_UP = 1;
constexpr int PLAYER_MOVE_DOWN = 2;
constexpr int PLAYER_MOVE_RIGHT = 3;
constexpr int PLAYER_MOVE_LEFT = 4;
constexpr int PLAYER_STOP = 5;

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
  std::cout << "preparinig to create map object" << std::endl;
  map = new Map();

  std::cout << "finished create map object" << std::endl;

  player.addComponent<ECS::Transformable>(400, 320, 64, 48, 1);
  player.addComponent<ECS::Sprite>(
      std::string("universal-lpc-sprite_male_01_walk-3frame.png"));
  player.addComponent<ECS::Animation>(3, 100);
  auto &key = player.addComponent<ECS::Keyboard>(&event);

  key.registerKeyDown(SDLK_UP, PLAYER_MOVE_UP);
  key.registerKeyUp(SDLK_UP, PLAYER_STOP);

  key.registerKeyDown(SDLK_DOWN, PLAYER_MOVE_DOWN);
  key.registerKeyUp(SDLK_DOWN, PLAYER_STOP);
  key.registerKeyDown(SDLK_RIGHT, PLAYER_MOVE_RIGHT);
  key.registerKeyUp(SDLK_RIGHT, PLAYER_STOP);
  key.registerKeyDown(SDLK_LEFT, PLAYER_MOVE_LEFT);
  key.registerKeyUp(SDLK_LEFT, PLAYER_STOP);
  key.registerKeyDown(SDLK_a, PLAYER_MOVE_LEFT);
  key.registerKeyUp(SDLK_a, PLAYER_STOP);

  player.addComponent<ECS::Collider>(std::string("player"), player);

  player.addGroup(groupPlayers);

  std::cout << "preparinig to load map" << std::endl;
  Map::LoadMap("map.csv", 30, 30);

  std::cout << "finish load map" << std::endl;
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
void processAction(int action) {
  if (action != 0) {
    ECS::Transformable &transform = player.getComponent<ECS::Transformable>();
    ECS::Animation &animation = player.getComponent<ECS::Animation>();
    switch (action) {
    case PLAYER_MOVE_UP:
      transform.moveUp(1);
      animation.play(0);
      break;
    case PLAYER_MOVE_DOWN:
      transform.moveDown(1);
      animation.play(2);
      break;
    case PLAYER_MOVE_RIGHT:
      transform.moveRight(1);
      animation.play(1);
      break;
    case PLAYER_MOVE_LEFT:
      transform.moveLeft(1);
      animation.play(3);
      break;
    case PLAYER_STOP:
      transform.stop();
      animation.stop();
      break;
    default:
      break;
    };
  };
};

void Game::update() {
  // player->update();
  processAction(player.getComponent<ECS::Keyboard>().popAction());
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

void Game::addTile(int id, int row, int column) {
  // return if we get a bad number
  if (id < 0) {
    return;
  }
  constexpr int tileSetSize = 32;
  constexpr int tileSize = 32;
  // calculate x and y
  int xpos = column * tileSize;
  int ypos = row * tileSize;
  // calculate the id left and right digits so we can access that in our tileset
  auto digits = Utilities::getBase10Digits(id, 2);
  if (digits.size() != 2) {
    return;
  } // abort if we failed to return two digits
  int srcY = digits[0] * tileSetSize;
  int srcX = digits[1] * tileSetSize;

  const std::string mapFile = "tileset.png";

  auto &tile(manager.addEntity());
  // ERROR player has not been created when tiles are created. this results in
  // null and segment fault
  ECS::Transformable *pTrans = &player.getComponent<ECS::Transformable>();
  auto tex = ECS::TextureTileInfo(mapFile, srcX, srcY, tileSetSize);
  auto drawData = ECS::GameTileInfo(xpos, ypos, tileSize);
  tile.addComponent<ECS::Tile>(tex, drawData, pTrans);

  tile.addGroup(groupMap);
  // std::cout << id << "Tile created at (" << row << "," << column << ")" <<
  // std::endl;
}