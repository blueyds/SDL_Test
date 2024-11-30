#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <SDL.h>
#include <string>

class TextureManager {
public:
  static SDL_Texture *LoadTexture(std::string fileName);
  static void Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest);
};

#endif