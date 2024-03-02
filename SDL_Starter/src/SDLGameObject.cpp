#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) :
	GameObject(params),
	m_pos(params->getX(), params->getY()),
	m_vel(0, 0),
	m_acc(0, 0)
{
	m_width = params->getWidth();
	m_height = params->getHeight();
	m_textureID = params->getTextureID();

	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(
		m_textureID,
		(int)m_pos.getX(), (int)m_pos.getY(),
		m_width, m_height,
		m_currentRow, m_currentFrame,
		Game::Instance()->getRenderer()
	);
}

void SDLGameObject::update()
{
	m_vel += m_acc;
	m_pos += m_vel;
}

void SDLGameObject::clean()
{
}

