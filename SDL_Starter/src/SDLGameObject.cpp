#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params)
{
	m_x = params->getX();
	m_y = params->getY();
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer());
}

void SDLGameObject::update()
{
}

void SDLGameObject::clean()
{
}
