#ifndef Player_h
#define Player_h

#include "Component.h"
#include <iostream>

class Player : public Component {
	public:
		Player() {};
		void print() {
			std::cout << "\t\tPlayer" << std::endl;
		};
};

#endif
