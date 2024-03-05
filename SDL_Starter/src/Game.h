#pragma once
#include "GameObject.h"
#include "GameStateMachine.h"
#include "SDL.h"
#include "vector"

class Game
{
public:

	static Game* Instance();

	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();

	bool running() { return m_running; }
	SDL_Renderer* getRenderer() const { return m_renderer; }

private:

	static Game* s_instance;

	Game();

	SDL_Window* m_window = 0;
	SDL_Renderer* m_renderer = 0;

	GameStateMachine* m_gameStateMachine;

	bool m_running = false;
	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;
};

