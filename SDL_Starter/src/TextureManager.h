#pragma once
#include "map"
#include "SDL.h"
#include "SDL_image.h"
#include "string"

class TextureManager
{
public:

	static TextureManager* Instance();

	~TextureManager();

	bool load(std::string filename, std::string id, SDL_Renderer* renderer);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:

	TextureManager();

	static TextureManager* s_instance;
	std::map<std::string, SDL_Texture*> m_textureMap;

};
