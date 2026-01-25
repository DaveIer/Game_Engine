#pragma once
#include"Game.h"

class GameObject
{
private:
	/// <param name="Texture"> image file path </param>
	GameObject(const char* TexturePath, int x, int y);
	~GameObject();

public:
	int xpos, ypos;
	SDL_Texture* Texture;

};

