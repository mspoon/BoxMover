#ifndef RenderSystem_h
#define RenderSystem_h

#include "Position.h"
#include "Drawable.h"
#include "Vector2D.h"
#include "System.h"
#include "SDL2/SDL.h"
#include "EntityManager.h"

#include <string>

class RenderSystem : public System {
	public:
		RenderSystem(EntityManager *em, SDL_Renderer *r);
		~RenderSystem();

		void update(uint32_t delta);

		SDL_Texture *loadImage(std::string filename);

	private:
		SDL_Renderer *renderer;

		void renderEntity(Drawable *draw, Position *pos);
};

#endif
