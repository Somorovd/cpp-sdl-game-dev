#include "Game.h"
#include "InputHandler.h"
#include "iostream"

InputHandler* InputHandler::s_instance = 0;

InputHandler::InputHandler() : m_mousePosition(0, 0)
{
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

InputHandler::~InputHandler() {}

void InputHandler::onKeyDown()
{
	m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
	m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onMouseMove(SDL_Event& event)
{
	m_mousePosition.setX(event.motion.x);
	m_mousePosition.setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
	m_mouseButtonStates[event.button.button - 1] = true;
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
	m_mouseButtonStates[event.button.button - 1] = false;
}

void InputHandler::onJoystickAxisMove(SDL_Event& event)
{
	int joy = event.jaxis.which;
	int val = getJoyValue01(event.jaxis.value);

	// left stick move left-right
	if (event.jaxis.axis == 0)
	{
		m_joystickValues[joy].first->setX(val);
	}
	// left stick move up-down
	if (event.jaxis.axis == 1)
	{
		m_joystickValues[joy].first->setY(val);
	}
	// right stick move left-right
	if (event.jaxis.axis == 2)
	{
		m_joystickValues[joy].second->setX(val);
	}

	// right stick move up-down
	if (event.jaxis.axis == 3)
	{
		m_joystickValues[joy].second->setY(val);
	}
}

void InputHandler::onJoystickButtonDown(SDL_Event& event)
{
	int joy = event.jaxis.which;
	m_buttonStates[joy][event.jbutton.button] = true;
}

void InputHandler::onJoystickButtonUp(SDL_Event& event)
{
	int joy = event.jaxis.which;
	m_buttonStates[joy][event.jbutton.button] = false;
}

int InputHandler::getJoyValue01(int v)
{
	if (v > m_joystickDeadZone)
	{
		return 1;
	}
	else if (v < -m_joystickDeadZone)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

InputHandler* InputHandler::Instance()
{
	if (s_instance == 0)
	{
		s_instance = new InputHandler();
	}

	return s_instance;
}

void InputHandler::update()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;
		case SDL_JOYAXISMOTION:
			onJoystickAxisMove(event);
			break;
		case SDL_JOYBUTTONDOWN:
			onJoystickButtonDown(event);
			break;
		case SDL_JOYBUTTONUP:
			onJoystickButtonUp(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}

void InputHandler::clean()
{
	if (m_joysticksInitialized)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

void InputHandler::initializeJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			m_joysticks.push_back(joy);
			m_joystickValues.push_back(std::make_pair(
				new Vector2(0, 0), new Vector2(0, 0)
			));

			std::vector<bool> tempButtons;
			for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
			{
				tempButtons.push_back(false);
			}
			m_buttonStates.push_back(tempButtons);
		}

		SDL_JoystickEventState(SDL_ENABLE);
		m_joysticksInitialized = true;

		std::cout << "initialized " << m_joysticks.size() << " joystick(s)" << std::endl;
	}
	else
	{
		m_joysticksInitialized = false;
	}
}

int InputHandler::xvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->getX();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getX();
		}
	}
}

int InputHandler::yvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->getY();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getY();
		}
	}
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
	return m_buttonStates[joy][buttonNumber];
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else
		{
			return 0;
		}
	}

	return false;
}
