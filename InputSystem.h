#ifndef InputSystem_h
#define InputSystem_h

#include "System.h"
#include "Moveable.h"
#include "Player.h"

class InputSystem : public System {
	public:
		InputSystem(EntityManager *em);
		~InputSystem();

		void update(uint32_t delta);
};

#endif
