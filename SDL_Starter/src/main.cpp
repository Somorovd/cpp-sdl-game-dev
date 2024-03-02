#include "Game.h"
#include "SDL.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
	Uint32 frameStart, frameTime;
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
			frameStart = SDL_GetTicks();
			game->handleEvents();
			game->update();
			game->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		return -1;
	}

	game->clean();

	return 0;
}