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

	SDL_Texture* m_texture = 0;
	SDL_Rect m_srcRect;
	SDL_Rect m_destRect;

	bool m_running = false;

};

