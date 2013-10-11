#ifndef System_h
#define System_h

#include <cstdint>

#include "EntityManager.h"

class System {
	public:
		System(EntityManager *em);
		virtual ~System();

		virtual void update(uint32_t delta);

	protected:
		EntityManager *em;
};

#endif
