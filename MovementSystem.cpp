#include "MovementSystem.h"

MovementSystem::MovementSystem(EntityManager *em) :
		System(em) {
	//Nothing to do here
}

MovementSystem::~MovementSystem() {
	// Nothing to do here
}

void MovementSystem::update(uint32_t delta) {
	// Get set of entities with our primary component
	std::set<EntityID> entities = em->getEntitiesWithComponent(typeid(Moveable));

	// If set is empty, then we have nothing to do
	if (entities.empty())
		return;

	std::set<EntityID>::iterator e;
	for (e = entities.begin(); e != entities.end(); e++) {
		Moveable *move = dynamic_cast<Moveable*>(em->getComponent(*e, typeid(Moveable)));
		Position *pos = dynamic_cast<Position*>(em->getComponent(*e, typeid(Position)));

		// Move the entity
		pos->p += (move->vel * (delta / 1000.0));
	}
}
