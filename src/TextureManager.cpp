#include "TextureManager.hpp"
#include "SDL_image.h"
#include "game.hpp"
#include <iostream>

SDL_Texture *TextureManager::LoadTexture(const char *fileName) {
  SDL_Surface *tmpSurface = IMG_Load(fileName);

  SDL_Texture *texture;
  texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
  if (!texture) {
    // txture was invalid
    std::cout << "[WARNING] Invalid texture from fileName: " << fileName
              << std::endl;
  };
  SDL_FreeSurface(tmpSurface);
  return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest) {
  SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}