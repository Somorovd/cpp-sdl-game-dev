#include "Game.h"
#include "InputHandler.h"
#include "iostream"
#include "PauseState.h"
#include "Player.h"
#include "PlayState.h"
#include "TextureManager.h"


const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{

	InputHandler* input = InputHandler::Instance();
	if (input->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	TextureManager* textureManager = TextureManager::Instance();
	if (!textureManager->load("assets/walk-basic.png", "player", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* player = new Player(new LoaderParams(100, 100, 64, 128, "player"));
	m_gameObjects.push_back(player);

	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("player");
	std::cout << "exiting PlayState" << std::endl;
	return true;
}