#include "InputHandler.h"
#include "iostream"
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
	m_vel.setX(0);
	m_vel.setY(0);

	handleInput();

	m_currentFrame = int((SDL_GetTicks() / 100) % 9) + 1;
	SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	InputHandler* input = InputHandler::Instance();

	if (!input->joysticksInitialized())
	{
		return;
	}

	int leftH = input->xvalue(0, 1);
	int leftV = input->yvalue(0, 1);
	int rightH = input->xvalue(0, 2);
	int rightV = input->yvalue(0, 2);

	if (leftH != 0)
	{
		m_vel.setX(1 * leftH);
	}
	if (leftV != 0)
	{
		m_vel.setY(1 * leftV);
	}
	if (rightH != 0)
	{
		m_vel.setX(1 * rightH);
	}
	if (rightV != 0)
	{
		m_vel.setY(1 * rightV);
	}

	// A Button
	if (input->getButtonState(0, 0))
	{
		std::cout << "button 0" << std::endl;
	}
	// B Button
	if (input->getButtonState(0, 1))
	{
		std::cout << "button 1" << std::endl;
	}
	// X Button
	if (input->getButtonState(0, 2))
	{
		std::cout << "button 2" << std::endl;
	}
	// Y Button
	if (input->getButtonState(0, 3))
	{
		std::cout << "button 3" << std::endl;
	}

	if (input->getMouseButtonState(LEFT))
	{
		std::cout << "left click" << std::endl;
	}
}
