#ifndef MAP_H_12532
#define MAP_H_12532
#include <string>

class Map {

public:
  Map();
  ~Map();

  static void LoadMap(std::string path, int sizeX, int sizeY);
};

#endif