#ifndef Moveable_h
#define Moveable_h

#include "Component.h"
#include "Vector2D.h"

#include <iostream>

class Moveable : public Component {
	public:
		Moveable(int velX, int velY) {
			vel.x = velX;
			vel.y = velY;
		}

		Vector2D vel;

		void print() {
			std::cout << "\t\tVelocity: (" << vel.x << ", " << vel.y << ")" << std::endl;
		}
};

#endif
