#ifndef arcadia_EntityManager_h
#define arcadia_EntityManager_h

#include "Component.h"

#include <set>
#include <unordered_map>
#include <list>
#include <typeinfo>
#include <typeindex>


typedef unsigned int EntityID ;

class EntityManager {
	public:
		EntityManager();
		~EntityManager();

		EntityID createEntity();
		void killEntity(EntityID e);

		bool addComponent(EntityID e, Component *c);
		Component *getComponent(EntityID e, std::type_index type);
		bool removeComponent(EntityID e, std::type_index type);

		std::list<Component *> getComponentsofType(std::type_index type);
		std::set<EntityID> getEntitiesWithComponent(std::type_index type);
		std::unordered_map<EntityID, Component *> *getComponentsByEntity(std::type_index type);

	private:
		std::set<EntityID> entityList;
		std::unordered_map<std::type_index, std::unordered_map<EntityID, Component *>> components;
};

#endif
