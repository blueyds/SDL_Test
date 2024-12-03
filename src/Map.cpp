#include "Map.hpp"
#include "game.hpp"
#include <fstream>
#include <iostream>

Map::Map() {}

Map::~Map() {}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
  char c;
  std::fstream mapFile;
  mapFile.open(path);
  int srcX, srcY;

  for (int y = 0; y < sizeY; y++) {
    for (int x = 0; x < sizeX; x++) {
      // read the first digit of map for our y pos in the tileset
      mapFile.get(c);
      srcY = atoi(&c) * 32;
     // std::cout << c;
      mapFile.get(c);
      srcX = atoi(&c) * 32;
      //std::cout << c << ",";

      Game::addTile(srcX, srcY, x * 32, y * 32);
  
      mapFile.ignore();
      
    }
  }

  mapFile.close();
}
