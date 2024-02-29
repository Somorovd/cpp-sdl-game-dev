#include <SDL.h>

SDL_Window* window = 0;
SDL_Renderer* renderer = 0;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		window = SDL_CreateWindow(
			"SDL Starter",
			SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
			1000, 800, 
			SDL_WINDOW_SHOWN
		);

		renderer = SDL_CreateRenderer(window, -1, 0);
	} 
	else
	{
		return 1;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	SDL_Quit();

	return 0;
}