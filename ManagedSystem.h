#ifndef ManagedSystem_h
#define ManagedSystem_h

#include "System.h"
#include <vector>

class ManagedSystem : public System {
	public:
		ManagedSystem(EntityManager *em);
		virtual ~ManagedSystem();

		void update(uint32_t delta);
		virtual void update(EntityID e, uint32_t delta);

	protected:
		std::vector<std::type_index> requiredComponents;

		void addRequiredComponent(std::type_index componentType);
};
#endif
