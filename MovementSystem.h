#ifndef MovementSystem_h
#define MovementSystem_h

#include "ManagedSystem.h"
#include "Position.h"
#include "Moveable.h"
#include "Vector2D.h"

class MovementSystem : public ManagedSystem {
	public:
		MovementSystem(EntityManager *em);
		~MovementSystem();

		using ManagedSystem::update;
		void update(EntityID e, uint32_t delta);
};

#endif
