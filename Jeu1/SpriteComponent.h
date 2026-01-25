#pragma once

#include "Components.h"
#include <SDL3/SDL.h>

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_FRect srcRect, destRect;

public:
	SpriteComponent() = delete; // Forbid to use default constructor, not sure about this line yet
	SpriteComponent(const char* path, float w = 16., float h = 16.)
		:transform(nullptr), srcRect(), destRect()
	{
		setTexture(path);
		srcRect.w = w; // redundant with init() -> will think about wich way's better
		srcRect.h = h; // redundant with init() -> will think about wich way's better
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void init() override
	{
		if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0.;
		srcRect.w = transform->width; // might be erased
		srcRect.h = transform->height; // might be erased
		destRect.w = srcRect.w * transform->scale;
		destRect.h = srcRect.h * transform->scale;
	}

	void update() override
	{
		destRect.x = transform->position.x;
		destRect.y = transform->position.y;
		destRect.w = srcRect.w * transform->scale;
		destRect.h = srcRect.h * transform->scale;
	}

	void render() override
	{
		TextureManager::Render(texture, &srcRect, &destRect);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
};

