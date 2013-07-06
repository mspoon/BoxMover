#ifndef Position_h
#define Position_h

#include "Component.h"
#include "Vector2D.h"

#include <iostream>

class Position : public Component {
	public:
		Position(int x, int y) {
			p.x = x;
			p.y = y;
		}

		Vector2D p;

		void print() {
			std::cout << "\t\tPosition: (" << p.x << ", " << p.y << ")" << std::endl;
		}
};

#endif
