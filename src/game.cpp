#include <iostream>

#include "game.hpp"
#include "Map.h"
#include "SDL_image.h"
#include "gameObject.hpp"

#include "ECS.h"
#include "Components.h"

GameObject *player;
Map *map;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game(/* args */) {}

Game::~Game() {}

SDL_Renderer *Game::renderer = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created" << std::endl;
		} else {
			std::cout << "Window Failed" << std::endl;
		}
		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	} else {
		isRunning = false;
	}
	player = new GameObject("Sara_16x18_Preview.png", 0, 0);
	map = new Map();
	newPlayer.addComponent<PositionComponent>();
	newPlayer.a
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		/* code */
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() { 
	player->update(); 
	manager.update();
	int x = newPlayer.getComponent<PositionComponent>.x();
	int y = newPlayer.getComponent<PositionComponent>.y();
	std::cout << x << "," << y << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	// this is where we add stuff to render
	map->DrawMap();
	player->render();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
