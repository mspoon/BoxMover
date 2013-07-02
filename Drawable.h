#ifndef Drawable_h
#define Drawable_h

#include "Component.h"
#include "Vector2D.h"
#include "SDL2/SDL.h"

class Drawable : public Component {
	public:
		Drawable(SDL_Texture *t) {
			texture = t;
			int x;
			int y;

			if (texture != nullptr)
				SDL_QueryTexture(texture, NULL, NULL, &x, &y);
				size = Vector2D(static_cast<float>(x), static_cast<float>(y));
		}

		~Drawable() {
			if (texture != nullptr)
				SDL_DestroyTexture(texture);
		}

		SDL_Texture *texture;
		Vector2D size;
};

#endif
