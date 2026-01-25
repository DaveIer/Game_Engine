#include "Collision.h"

bool Collision::AABB(const SDL_FRect& recA, const SDL_FRect& recB)
{
	return (
		recA.x + recA.w >= recB.x &&
		recB.x + recB.w >= recA.x &&
		recA.y + recA.h >= recB.y &&
		recB.y + recB.h >= recA.y
		);
}
