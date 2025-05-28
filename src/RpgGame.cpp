#include "RpgGame.hpp"
#include <iostream>

constexpr int PLAYER_MOVE_UP = 1;
constexpr int PLAYER_MOVE_DOWN = 2;
constexpr int PLAYER_MOVE_RIGHT = 3;
constexpr int PLAYER_MOVE_LEFT = 4;
constexpr int PLAYER_STOP = 5;

enum groupLabels : std::size_t {
  groupMap,
  groupPlayers,
  groupEnemies,
  groupColliders
};

  ECS::Manager *RpgGame::s_manager = nullptr;
  ECS::Entity *RpgGame::s_player = nullptr;

void RpgGame::BuildScene() {

  // player = new GameObject("Sara_16x18_Preview.png", 0, 0);
  std::cout << "preparinig to create map object" << std::endl;
  ECS::MapTiledCSV map = ECS::MapTiledCSV(this->manager);

  std::cout << "finished create map object" << std::endl;
  ECS::Entity &tempPlayer = this->manager.addEntity();
  player = std::addressof(tempPlayer);
  player->addComponent<ECS::Transformable>(400, 320, 64, 48, 1);
  player->addComponent<ECS::Sprite>(
      std::string("universal-lpc-sprite_male_01_walk-3frame.png"));
  player->addComponent<ECS::Animation>(3, 100);
  auto &key = player->addComponent<ECS::Keyboard>(&event);

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

  player->addComponent<ECS::Collider>(std::string("player"),tempPlayer);

  player->addGroup(groupPlayers);
  RpgGame::s_manager = std::addressof(this->manager);
  RpgGame::s_player = this->player;
  std::cout << "preparinig to load map" << std::endl;
  map.loadMap("map.csv", 30, 30);

  std::cout << "finish load map" << std::endl;


}

void RpgGame::processAction(int action) {
  if (action != 0) {
    ECS::Transformable &transform = player->getComponent<ECS::Transformable>();
    ECS::Animation &animation = player->getComponent<ECS::Animation>();
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

void RpgGame::update() {
  // player->update();
  processAction(player->getComponent<ECS::Keyboard>().popAction());
  manager.refresh();
  manager.update();
}

void RpgGame::render() {
  SDL_RenderClear(renderer);
  // this is where we add stuff to render
  // map->DrawMap();
  // player->render();
  manager.drawGroup(groupMap);
  manager.drawGroup(groupPlayers);
  manager.drawGroup(groupEnemies);

  SDL_RenderPresent(renderer);
}

void RpgGame::addTile(int id, int row, int column) {
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

  auto &tile(RpgGame::s_manager->addEntity());
  // ERROR player has not been created when tiles are created. this results in
  // null and segment fault
  ECS::Transformable *pTrans =
      &RpgGame::s_player->getComponent<ECS::Transformable>();
  auto tex = ECS::TextureTileInfo(mapFile, srcX, srcY, tileSetSize);
  auto drawData = ECS::GameTileInfo(xpos, ypos, tileSize);
  tile.addComponent<ECS::Tile>(tex, drawData, pTrans);

  tile.addGroup(groupMap);
  // std::cout << id << "Tile created at (" << row << "," << column << ")" <<
  // std::endl;
}