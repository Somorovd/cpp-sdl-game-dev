#pragma once
#include "SDL.h"
#include "vector"
#include "Vector2.h"

class InputHandler
{
public:

	static InputHandler* Instance();

	void update();
	void clean();

	void initializeJoysticks();
	bool joysticksInitialized() { return m_joysticksInitialized; }

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	bool getButtonState(int joy, int buttonNumber);

private:

	static InputHandler* s_instance;

	InputHandler();
	~InputHandler();

	int getJoyValue01(int v);

	bool m_joysticksInitialized = false;
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2*, Vector2*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;

	const int m_joystickDeadZone = 10000;
};

