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
	m_x += 1;
	m_currentFrame = int((SDL_GetTicks() / 100) % 9) + 1;
}

void Player::clean()
{
}
