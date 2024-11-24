#ifndeg MAP_H_12532
#define MAP_H_12532
#include "SDL.h"

class Map{

public:

    Map();
    ~Map();
    
    void LoadMap(int arr[20][25]);
    void DrawMap();
    
private:
    
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Tecture* grass;
    SDL_Texture* water;
    
    int map[20][25];
    
};

#endif