#pragma once
#include "GameObject.h"
#include "string"

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const LoaderParams* params);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	int m_x, m_y, m_width, m_height;
	int m_currentRow, m_currentFrame;
	std::string m_textureID;
};

