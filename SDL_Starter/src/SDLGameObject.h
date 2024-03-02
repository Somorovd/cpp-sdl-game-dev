#pragma once
#include "GameObject.h"
#include "string"
#include "Vector2.h"

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const LoaderParams* params);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	Vector2 m_pos;
	int m_width, m_height;
	int m_currentRow, m_currentFrame;
	std::string m_textureID;
};

