#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* TexturePath, int x, int y)
	:xpos(x), ypos(y)
{
	Texture = TextureManager::LoadTexture(TexturePath);
}

GameObject::~GameObject() {

}