#pragma once
#include "SDLGameObject.h"

enum ButtonState
{
	MOUSE_OUT = 1,
	MOUSE_OVER = 2,
	CLICKED = 3
};

class MenuButton : public SDLGameObject
{
public:

	MenuButton(const LoaderParams* params, void (*callback)());

	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void (*m_callback)();
	bool m_released = false;
};

