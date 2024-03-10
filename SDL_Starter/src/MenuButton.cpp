#include "InputHandler.h"
#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* params) :
	SDLGameObject(params)
{
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw()
{
	SDLGameObject::draw();
}

void MenuButton::update()
{
	Vector2 mousePos = InputHandler::Instance()->getMousePosition();

	if (
		mousePos.getX() < (m_pos.getX() + m_width)
		&& mousePos.getX() > m_pos.getX()
		&& mousePos.getY() < (m_pos.getY() + m_height)
		&& mousePos.getY() > m_pos.getY()
		)
	{
		m_currentFrame = MOUSE_OVER;

		if (InputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
