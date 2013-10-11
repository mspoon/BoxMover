#ifndef arcadia_EntityManager_h
#define arcadia_EntityManager_h

#include "Component.h"

#include <set>
#include <map>
#include <list>
#include <vector>
#include <typeinfo>
#include <typeindex>


//typedef unsigned int EntityID ;

#define EntityID unsigned int

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
		std::map<EntityID, Component *> *getComponentsByEntity(std::type_index type);
		std::vector<EntityID> getEntitiesWithComponents(std::vector<std::type_index> types);

	private:
		std::set<EntityID> entityList;
		std::map<std::type_index, std::map<EntityID, Component *>> components;
};

#endif
