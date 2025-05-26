#include "Map.hpp"
#include "game.hpp"
#include "Utilities.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

Map::Map() {}

Map::~Map() {}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
  
  std::fstream mapFile;
  
  mapFile.open(path);

  int row = 0;
  std::string fileLine = "";
  while(std::getline(mapFile, fileLine)) {
    //std::istringstream line(fileLine);
    int count = fileLine.size();
    int column = 0;
    int i = 0;
    int digit = -1;
    int tileId = -1;
    std::string input = "";
    while(i < count) {
      // read the first digit of map for our y pos in the tileset
      // read the first digit of map for our y pos in the tileset
      input = std::string(1,fileLine.at(i));
      // con      input = std::string(1,fileLine.at(i));
      // convert the input to a number
      int temp = Utilities::getDigit(input);
      if (temp >= 0){digit = temp;}
      if(digit >= 0){
        // do somthing if the digit is 0 or greater
        if(tileId < 0){
          // the current id has not been set therefore this is first input
          tileId = digit * 10;
        } else {
          // the current id has been cresated therefore this is second input
          tileId += digit;
          Game::addTile(tileId, row, column);
          column += 1;
          tileId = -1;
          digit = -1;
          input = "";
        };

      };
      i++;
    };
    std::cout << "Reading Row " << row << std::endl; 
    row = row + 1;
    column = 0;
  }

  mapFile.close();
}
