#include "Player.h"
#include "SDL.h"

Player::Player(const LoaderParams* params) : SDLGameObject(params)
{
}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	//m_pos.setX(m_pos.getX() + 1);
	//m_vel.setX(1);
	m_acc.setX(1);
	m_currentFrame = int((SDL_GetTicks() / 100) % 9) + 1;
	SDLGameObject::update();
}

void Player::clean()
{
}
