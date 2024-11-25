#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include "SDL.h"

class TextureManager {
public:
  static SDL_Texture *LoadTexture(const char *fileName);
  static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
};

#endif