#include "RenderSystem.h"

#include <iostream>

RenderSystem::RenderSystem(EntityManager *em, SDL_Renderer *r) :
		System(em) {
	renderer = r;
}

RenderSystem::~RenderSystem() {
	// Nothing to do here, we don't own renderer or entitymanager
}

void RenderSystem::update(uint32_t delta) {
	// Get set of entities with our primariy component
	std::set<EntityID> entities = em->getEntitiesWithComponent(typeid(Drawable));

	// If set is empty, then we have nothing to do
	if (entities.empty())
		return;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	std::set<EntityID>::iterator e;
	for (e = entities.begin(); e != entities.end(); e++) {
		Drawable *draw = dynamic_cast<Drawable*>(em->getComponent(*e, typeid(Drawable)));
		Position *pos = dynamic_cast<Position*>(em->getComponent(*e, typeid(Position)));

		renderEntity(draw, pos);
	}

	SDL_RenderPresent(renderer);
}

SDL_Texture *RenderSystem::loadImage(std::string filename) {
	SDL_Surface *surf = SDL_LoadBMP(filename.c_str());

	if (surf == nullptr)
		return nullptr;

	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);
	
	return text;
}

void RenderSystem::renderEntity(Drawable *draw, Position *pos) {
	if (draw == nullptr || pos == nullptr)
		return;

	if (draw->texture == nullptr)
		return;

	SDL_Rect srcRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = draw->size.x;
	srcRect.h = draw->size.y;

	SDL_Rect destRect;
	destRect.x = pos->p.x;
	destRect.y = pos->p.y;
	destRect.w = srcRect.w * draw->scale;
	destRect.h = srcRect.h * draw->scale;

	if (SDL_RenderCopy(renderer, draw->texture, &srcRect, &destRect) < 0)
		std::cerr << "Error Rendering Texture: " << SDL_GetError() << std::endl;

	return;
}
