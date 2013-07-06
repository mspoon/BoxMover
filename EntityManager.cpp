#include "EntityManager.h"

#include <iostream>

EntityManager::EntityManager() {
}

EntityManager::~EntityManager() {
	std::set<EntityID>::iterator it = entityList.begin();
	while (it!=entityList.end()) {
		std::cout << "Cleaning up Entity " << *it << std::endl;
		// We already have a function to handle safely killing the entity
		// and dealing with component pointers.
		killEntity(*it);
		std::cout << "Entity killed" << std::endl;
		it++;
	}
}

EntityID EntityManager::createEntity() {
	// Find next available value
	// Only if list is not empty
	EntityID e = 1;

	if (entityList.size() > 0) {
		std::set<EntityID>::iterator last = entityList.end();
		last--;
		e = *last;
		//Increment e until no entity has the value
		while (entityList.count(++e) != 0);
	}

	entityList.insert(e);

	return e;
}

void EntityManager::killEntity(EntityID e) {
	std::cout << "Entering EntityManager::killEntity(" << e << ")" << std::endl;
	std::map<std::type_index, std::map<EntityID, Component *>>::iterator itType;
	itType = components.begin();
	std::cout << "\tGot first component list" << std::endl;

	while (itType != components.end()) {
		std::cout << "\t\tTest if component list has entity" << std::endl;
		if (itType->second.count(e) != 0) {
			std::cout << "\t\t\tRemoving component" << std::endl;
			removeComponent(e, itType->first);
			itType++;
			std::cout << "\t\t\tComponent removed" << std::endl;
		}
	}
	std::cout << "\tKill entity" << std::endl;
	entityList.erase(e);
	std::cout << "Exiting EntityManager::killEntity(" << e << ")" << std::endl;
}

bool EntityManager::addComponent(EntityID e, Component *c) {
	components[std::type_index(typeid(*c))][e] = c;

	return true;
}

Component *EntityManager::getComponent(EntityID e, std::type_index type) {
	Component *c = nullptr;

	if (components[type].count(e) != 0)
		c = components[type][e];

	return c;
}

bool EntityManager::removeComponent(EntityID e, std::type_index type) {
	if (components[type].count(e) != 0) {
		// Save off the pointer so we don't have memory leaks
		Component *c = components[type][e];
		components[type].erase(e);
		delete c;
	}

	return true;
}

std::list<Component *> EntityManager::getComponentsofType(std::type_index type) {
	// TODO: implement this
	std::list<Component *> l;
	return l;
}

std::set<EntityID> EntityManager::getEntitiesWithComponent(std::type_index type) {
	std::set<EntityID> es;
	std::map<EntityID, Component *>::iterator it = components[type].begin();
	while (it != components[type].end()) {
		es.insert(it->first);
		it++;
	}

	return es;
}

std::map<EntityID, Component *> *EntityManager::getComponentsByEntity(std::type_index type) {
	std::map<EntityID, Component*> empty;
	if (components.count(type))
		return &(components[type]);
	else
		return nullptr;
}
