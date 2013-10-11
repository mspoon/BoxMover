#ifndef InputSystem_h
#define InputSystem_h

#include "ManagedSystem.h"
#include "Moveable.h"
#include "Player.h"

class InputSystem : public ManagedSystem {
	public:
		InputSystem(EntityManager *em);
		~InputSystem();

		using ManagedSystem::update;
		void update(EntityID e, uint32_t delta);
};

#endif
