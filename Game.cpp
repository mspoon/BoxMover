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
	// Failsafe
	cleanup();
}

bool Game::execute() {
	lastTime = SDL_GetTicks();

	running = init();

	while (running) {
		uint32_t curTime = SDL_GetTicks();
		dt = curTime - lastTime;
		lastTime = curTime;

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

	window = SDL_CreateWindow("BoxMover", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, scrWidth, scrHeight, SDL_WINDOW_SHOWN);

	if (window == nullptr)
		return false;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
		return false;

	SDL_RenderPresent(renderer);

	// Create entities
	em = new EntityManager();
	renderSystem = new RenderSystem(em, renderer);

	EntityID e = em->createEntity();
	em->addComponent(e, new Position(40, 40));
	//em->addComponent(e, new Drawable(renderSystem->loadImage("SmileyFace.bmp")));

	return true;
}

void Game::event() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						running = false;
						break;
				}
		}
	}
}

void Game::loop() {
	// TODO: void Game logic goes here
}

void Game::render() {
	//renderSystem->update(dt);
}

void Game:: cleanup() {
	if (renderSystem != nullptr) {
		delete renderSystem;
		renderSystem = nullptr;
	}

	if (em != nullptr) {
		delete em;
		em = nullptr;
	}

	if (renderer != nullptr) {
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}

	if (window != nullptr) {
		SDL_DestroyWindow(window);
		window = nullptr;

		// Assume if window has been deleted, the SDL has been taken care of, too
		SDL_Quit();
	}
}
