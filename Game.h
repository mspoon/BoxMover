#ifndef Game_h
#define Game_h

#include "SDL2/SDL.h"
#include "EntityManager.h"
#include "RenderSystem.h"
#include "MovementSystem.h"
#include "InputSystem.h"

class Game {
	public:
		Game();
		~Game();

		bool execute();

	private:
		bool init();
		void event();
		void loop();
		void render();
		void cleanup();

		int scrWidth,scrHeight;
		bool running;

		SDL_Window *window;
		SDL_Renderer *renderer;

		EntityManager *em;
		RenderSystem *renderSystem;
		MovementSystem *movementSystem;
		InputSystem *inputSystem;

		uint32_t dt;
		uint32_t lastTime;
};

#endif
