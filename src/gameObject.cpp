#include "gameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet,int x, int y){
    objTexture = TextureManager::LoadTexture(textureSheet, ren);
    xpos = x;
    ypos = y;
    srcRect.h  = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    
}

GameObject::~GameObject(){};

void GameObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

void GameObject::update(){
    xpos++;
    ypos++;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}