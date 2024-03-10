#include "InputHandler.h"
#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* params, void (*callback)()) :
	SDLGameObject(params),
	m_callback(callback)
{
	m_currentFrame = 0;
	m_currentRow = MOUSE_OUT;
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
		bool isLeftClick = InputHandler::Instance()->getMouseButtonState(LEFT);

		if (isLeftClick && m_released)
		{
			m_currentRow = CLICKED;
			m_callback();
			m_released = false;
		}
		else if (!isLeftClick)
		{
			m_released = true;
			m_currentRow = MOUSE_OVER;
		}
	}
	else
	{
		m_currentRow = MOUSE_OUT;
	}
}

void MenuButton::clean()
{
	SDLGameObject::clean();
}
