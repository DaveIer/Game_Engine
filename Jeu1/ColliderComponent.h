#pragma once

#include "Components.h"

class ColliderComponent : public Component
{
private:
	TransformComponent* transform;

public:
	SDL_FRect collider;
	//std::string tag; // not sure of its utility for now

	void init() override
	{
		if (!entity->hasComponent<TransformComponent>()) entity->addComponent<TransformComponent>();
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		collider.x = transform->position.x;
		collider.y = transform->position.y;
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};
