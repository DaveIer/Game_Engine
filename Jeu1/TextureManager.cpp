#include "TextureManager.h"
#include <iostream>
#include <SDL3_image/SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* file) {
	SDL_Surface* surface = IMG_Load(file);
	if (!surface) std::cout << "file \"" << file << "\" not found!" << std::endl;
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	if (!texture) std::cout << "Failed to create texture from file \"" << file << "\"!" << std::endl;
	SDL_DestroySurface(surface);

	return texture;
}

void TextureManager::Render(SDL_Texture* tex, const SDL_FRect* src, const SDL_FRect* dest)
{
	SDL_RenderTexture(Game::renderer, tex, src, dest);
}