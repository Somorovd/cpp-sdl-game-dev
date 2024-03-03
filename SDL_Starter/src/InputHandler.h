#pragma once
#include "SDL.h"
#include "vector"
#include "Vector2.h"

enum MouseButtons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

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

	bool getMouseButtonState(int buttonNumber);
	Vector2 getMousePosition() { return m_mousePosition; }

	bool isKeyDown(SDL_Scancode key);

private:

	static InputHandler* s_instance;

	InputHandler();
	~InputHandler();

	void onKeyDown();
	void onKeyUp();

	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);
	int getJoyValue01(int v);

	bool m_joysticksInitialized = false;
	const int m_joystickDeadZone = 10000;
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2*, Vector2*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;

	std::vector<bool> m_mouseButtonStates;
	Vector2 m_mousePosition;

	// pointer to an array of keystates from SDL_GetKeysboardState(...)
	const Uint8* m_keystates;

};

