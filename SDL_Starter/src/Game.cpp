#include "Game.h"
#include "iostream"
#include "SDL_image.h"
#include "TextureManager.h"

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

	TextureManager::Instance()->load("assets/walk-basic.png", "walk-basic", m_renderer);

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_renderer);

	TextureManager::Instance()->drawFrame("walk-basic", 0, 0, 64, 128, 1, m_currentFrame, m_renderer);

	SDL_RenderPresent(m_renderer);
}

void Game::update()
{
	m_currentFrame = ((SDL_GetTicks() / 100) % 9) + 1;
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
