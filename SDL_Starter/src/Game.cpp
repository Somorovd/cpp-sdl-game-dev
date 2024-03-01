#include "Game.h"
#include "iostream"
#include "SDL_image.h"

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		std::cout << "SDL init success" << std::endl;
		m_window = SDL_CreateWindow(
			title, xpos, ypos, width, height, flags
		);

		if (m_window != 0)
		{
			std::cout << "window creation success" << std::endl;
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);

			if (m_renderer != 0)
			{
				std::cout << "renderer creation success" << std::endl;
				SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer creation fail" << std::endl;
				return false;
			}

		}
		else
		{
			std::cout << "window creation fail" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail" << std::endl;
		return false;
	}

	std::cout << "init success" << std::endl;
	m_running = true;

	SDL_Surface* tempSurface = IMG_Load("assets/walk-basic.png");
	m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	m_destRect.x = m_srcRect.x = 0;
	m_destRect.y = m_srcRect.y = 0;
	m_destRect.w = m_srcRect.w = 64;
	m_destRect.h = m_srcRect.h = 128;

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_renderer);

	//SDL_RenderCopy(m_renderer, m_texture, &m_srcRect, &m_destRect);
	SDL_RenderCopyEx(m_renderer, m_texture, &m_srcRect, &m_destRect, 0, 0, SDL_FLIP_HORIZONTAL);

	SDL_RenderPresent(m_renderer);
}

void Game::update()
{
	m_srcRect.x = 64 * ((SDL_GetTicks() / 100) % 9) + 64;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_running = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game" << std::endl;
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}
