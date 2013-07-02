#include "System.h"

System::System(EntityManager *em) {
	this->em = em;
}

System::~System() {
}

void System::update(uint32_t delta) {
}
