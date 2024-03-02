#pragma once
#include "SDL.h"

class Game
{
public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_running; }

private:

	SDL_Window* m_window = 0;
	SDL_Renderer* m_renderer = 0;

	bool m_running = false;
	int m_currentFrame;

};

