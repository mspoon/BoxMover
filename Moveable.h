#ifndef Moveable_h
#define Moveable_h

#include "Component.h"
#include "Vector2D.h"

#include <iostream>

class Moveable : public Component {
	public:
		Moveable(int velX, int velY) {
			velocity.x = velX;
			velocity.y = velY;
		}

		Vector2D velocity;

		void print() {
			std::cout << "\t\tVelocity: (" << velocity.x << ", " << velocity.y << ")" << std::endl;
		}
};

#endif
