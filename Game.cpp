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
	// TODO: Add initialzation code here
	return false;
}

void Game::event() {
	// TODO: Add event handling code here
}

void Game::loop() {
	// TODO: void Game logic goes here
}

void Game::render() {
	// TODO: Render logic goes here
}

void Game:: cleanup() {
	// TODO: Clean up your mess!
}
