#ifndef arcadia_System_h
#define arcadia_System_h

#include <cstdint>

class System {
	public:
		System();
		virtual ~System();

		virtual void update(uint32_t delta);
};

#endif
