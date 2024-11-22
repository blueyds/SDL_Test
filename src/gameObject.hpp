#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "SDL.h"

class GameObject {
public:

    GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
    ~GameObject();
    
    void update();
    void render();
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Renderer* renderer;
};

#endif