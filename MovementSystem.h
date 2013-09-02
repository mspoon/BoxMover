#ifndef MovementSystem_h
#define MovementSystem_h

#include "System.h"
#include "Position.h"
#include "Moveable.h"
#include "Vector2D.h"

class MovementSystem : public System {
	public:
		MovementSystem(EntityManager *em);
		~MovementSystem();

		void update(uint32_t delta);
};

#endif
