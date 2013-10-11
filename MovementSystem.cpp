#include "MovementSystem.h"

MovementSystem::MovementSystem(EntityManager *em) :
		ManagedSystem(em) {
	// Add required types to managedSystem
	addRequiredComponent(typeid(Moveable));
	addRequiredComponent(typeid(Position));
}

MovementSystem::~MovementSystem() {
	// Nothing to do here
}

void MovementSystem::update(EntityID e, uint32_t delta) {
	Moveable *move = dynamic_cast<Moveable*>(em->getComponent(e, typeid(Moveable)));
	Position *pos = dynamic_cast<Position*>(em->getComponent(e, typeid(Position)));

	// Move the entity
	pos->p += (move->vel * (delta / 1000.0));
}
