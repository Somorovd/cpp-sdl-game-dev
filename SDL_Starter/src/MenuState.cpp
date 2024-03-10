#include "Game.h"
#include "iostream"
#include "MenuButton.h"
#include "MenuState.h"
#include "TextureManager.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	TextureManager* textureManager = TextureManager::Instance();

	if (!textureManager->load("assets/play-button.png", "play-button", Game::Instance()->getRenderer()))
	{
		return false;
	}
	if (!textureManager->load("assets/exit-button.png", "exit-button", Game::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 128, 64, "play-button"));
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 128, 64, "exit-button"));

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState" << std::endl;
	return true;

}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("play-button");
	TextureManager::Instance()->clearFromTextureMap("exit-button");

	std::cout << "exiting MenuState" << std::endl;
	return true;
}