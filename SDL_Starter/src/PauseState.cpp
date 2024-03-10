#include "Game.h"
#include "InputHandler.h"
#include "iostream"
#include "LoaderParams.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PauseState.h"
#include "TextureManager.h"


const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::s_resumePlay()
{
	Game::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	TextureManager* textureManager = TextureManager::Instance();
	if (!textureManager->load("assets/play-button.png", "resume-button", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!textureManager->load("assets/exit-button.png", "main-button", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(
		new LoaderParams(200, 100, 128, 64, "main-button"),
		s_pauseToMain
	);
	GameObject* button2 = new MenuButton(
		new LoaderParams(200, 300, 128, 64, "resume-button"),
		s_resumePlay
	);

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering PauseState" << std::endl;
	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("resume-button");
	TextureManager::Instance()->clearFromTextureMap("main-button");

	std::cout << "exiting PauseState" << std::endl;
	return true;
}