#include "InputSystem.h"

#include "SDL2/SDL.h"

InputSystem::InputSystem(EntityManager *em) :
		ManagedSystem(em) {
	addRequiredComponent(typeid(Player));
	addRequiredComponent(typeid(Moveable));
}

InputSystem::~InputSystem() {
	// Nothing to do here
}

void InputSystem::update(EntityID e, uint32_t delta) {
	const Uint8* keyState = SDL_GetKeyboardState(NULL);

	Moveable *move = dynamic_cast<Moveable*>(em->getComponent(e, typeid(Moveable)));

	if (move == nullptr)
		return;

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
