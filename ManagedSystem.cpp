#include "ManagedSystem.h"

#include <iostream>

ManagedSystem::ManagedSystem(EntityManager *em) :
		System(em) {
	// Nothing to do here
	// In subclasses, this is where we might register required
	// components.
}

ManagedSystem::~ManagedSystem() {
}

void ManagedSystem::update(uint32_t delta) {
	std::vector<EntityID> entities = em->getEntitiesWithComponents(requiredComponents);

	std::vector<EntityID>::iterator e;
	
	for (e = entities.begin(); e != entities.end(); e++) {
		update(*e, delta);
	}
}

void ManagedSystem::update(EntityID e, uint32_t delta) {
	std::cerr << "Error: subclass of ManagedSystem did not implement void update(EntityID, uint32_t)!" << std::endl;
}

void ManagedSystem::addRequiredComponent(std::type_index componentType) {
	requiredComponents.push_back(componentType);
}
