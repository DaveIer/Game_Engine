#pragma once

#include "Game.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;

	KeyboardController() :transform(nullptr) {}

	void init() override
	{
		if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_EVENT_KEY_DOWN)
		{
			switch (Game::event.key.key)
			{
			case SDLK_D:
				transform->velocity.x = 1;
				break;

			case SDLK_Q:
				transform->velocity.x = -1;
				break;

			case SDLK_Z:
				transform->velocity.y = -1;
				break;

			case SDLK_S:
				transform->velocity.y = 1;
				break;

			default:
				// Unhandled key
				break;
			}
		}

		if (Game::event.type == SDL_EVENT_KEY_UP)
		{
			switch (Game::event.key.key)
			{
			case SDLK_D:
				transform->velocity.x = 0;
				break;

			case SDLK_Q:
				transform->velocity.x = 0;
				break;

			case SDLK_Z:
				transform->velocity.y = 0;
				break;

			case SDLK_S:
				transform->velocity.y = 0;
				break;
			default:
				// Unhandled key
				break;
			}
		}
	}
};
