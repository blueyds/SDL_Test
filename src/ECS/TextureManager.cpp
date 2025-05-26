#include <SDL2/SDL_image.h>
#include <iostream>

#include "TextureManager.hpp"
#include "game.hpp"

SDL_Texture *TextureManager::LoadTexture(std::string fileName) {
  SDL_Surface *tmpSurface = IMG_Load(fileName.c_str());

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