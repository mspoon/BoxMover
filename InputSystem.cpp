#include "InputSystem.h"

#include "SDL2/SDL.h"

InputSystem::InputSystem(EntityManager *em) :
		System(em) {
	// Nothing to do here
}

InputSystem::~InputSystem() {
	// Nothing to do here
}

void InputSystem::update(uint32_t delta) {
	// Get set of entities with our primary component
	std::set<EntityID> entities = em->getEntitiesWithComponent(typeid(Player));

	// If set is empty, we have nothing to do
	if (entities.empty())
		return;

	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	std::set<EntityID>::iterator e;
	for (e = entities.begin(); e != entities.end(); e++) {
		Moveable *move = dynamic_cast<Moveable*>(em->getComponent(*e, typeid(Moveable)));

		if (move == nullptr)
			continue;

		if (keyState[SDL_SCANCODE_UP])
			move->vel.y = -100;
		else if (keyState[SDL_SCANCODE_DOWN])
			move->vel.y = 100;
		else
			move->vel.y = 0;

		if (keyState[SDL_SCANCODE_LEFT])
			move->vel.x = -100;
		else if (keyState[SDL_SCANCODE_RIGHT])
			move->vel.x = 100;
		else
			move->vel.x = 0;
	}
}
