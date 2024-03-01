#include "Game.h"
#include "SDL.h"

Game* g_game = 0;

int main(int argc, char* argv[])
{
	g_game = new Game();
	g_game->init(
		"SDL Starter",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1000, 800,
		SDL_WINDOW_SHOWN
	);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->clean();

	return 0;
}