#ifndef Game_h
#define Game_h

class Game {
	public:
		Game();
		~Game();

		bool execute();

	private:
		bool init();
		void event();
		void loop();
		void render();
		void cleanup();

		int scrWidth,scrHeight;
		bool running;
};

#endif
