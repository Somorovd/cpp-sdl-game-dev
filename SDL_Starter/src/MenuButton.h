#pragma once
#include "SDLGameObject.h"

enum ButtonState
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public SDLGameObject
{
public:

	MenuButton(const LoaderParams* params);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:

};
