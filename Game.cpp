#include "Game.h"

int main(int argc, char **argv) {
	Game game;
	if (!game.execute()) {
		return 1;
	}

	return 0;
}

Game::Game() {
	scrWidth = 800;
	scrHeight = 600;

	running = false;
}

Game::~Game() {
}

bool Game::execute() {
	running = init();

	while (running) {
		event();
		loop();
		render();
	}

	cleanup();

	return true;
}

bool Game::init() {
	// Initialize SDL and create window
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return false;

	window = SDL_CreateWindow("BoxMover",
									  SDL_WINDOWPOS_CENTERED,
									  SDL_WINDOWPOS_CENTERED,
									  scrWidth, scrHeight,
									  SDL_WINDOW_SHOWN);

	if (window == nullptr)
		return false;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
		return false;

	SDL_RenderPresent(renderer);

	return true;
}

void Game::event() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
		}
	}
}

void Game::loop() {
	// TODO: void Game logic goes here
}

void Game::render() {
	// TODO: Render logic goes here
}

void Game:: cleanup() {
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	if (window != nullptr)
		SDL_DestroyWindow(window);

	SDL_Quit();
}
