#ifndef Position_h
#define Position_h

#include "Component.h"
#include "Vector2D.h"

class Position : public Component {
	public:
		Position(int x, int y) {
			p.x = x;
			p.y = y;
		}

		Vector2D p;
};

#endif
