#pragma once

#include "Game.h"

class TextureManager
{
public:
	/// <summary> Returns a SDL_Texture of the image </summary>
	/// <param name="file"> image file path</param>
	static SDL_Texture* LoadTexture(const char* file); // static to be able to use the function without an instance of the class
	static void Render(SDL_Texture* tex, const SDL_FRect* src, const SDL_FRect* dest);
};