#include "Game.h"
#include "SDL.h"

int main(int argc, char* argv[])
{

	Game* game = Game::Instance();

	if (game->init(
		"SDL Starter",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		1000, 800,
		SDL_WINDOW_SHOWN
	))
	{
		while (game->running())
		{
			game->handleEvents();
			game->update();
			game->render();

			SDL_Delay(10); // temporary delay until framerate cap
		}
	}
	else
	{
		return -1;
	}

	game->clean();

	return 0;
}