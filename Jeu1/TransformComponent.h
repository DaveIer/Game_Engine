#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;
	float speed, width, height, scale;

	/*TransformComponent()
		:position(), velocity()
	{
	
	}*/

	TransformComponent(float xpos = 0., float ypos = 0., float xVelocity = 0., float yVelocity = 0., float speed_ = 5., float width_ = 32., float height_ = 24., float scale_ = 3.)
		:position(xpos, ypos), velocity(xVelocity, yVelocity), speed(speed_), width(width_), height(height_), scale(scale_)
	{ 
		
	}

	void init()override
	{
		velocity.x = velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	/* Getters & Setters kept in commentary if I put "position" back in private
	int getX() const { return position.x; }
	int getY() const { return position.y; }
	void setX(int x) { position.x = x; }
	void setY(int y) { position.y = y; }
	void setPos(int x, int y) { position.x = x; position.y = y; }
	*/
};
