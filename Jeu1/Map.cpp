#include "Map.h"
#include "TextureManager.h"
#include <iostream>

Map::Map() 
{
	
}

Map::~Map() {
	
}

void Map::loadMap()
{
	
}

void Map::render(const int& tileNumberWidth, const int& tileNumberHeigth) {
	SDL_FRect src, dest;
	//src.x = 0;
	//src.y = 0;
	//src.w = 16;
	//src.h = 16;
	dest.x = 0;
	dest.y = 0;
	dest.w = 32;
	dest.h = 32;

	/*
	for (int row = 0; row < tileNumberHeigth; row++) {
		for (int column = 0; column < tileNumberWidth; column++) {
			int index = mapTab[row][column];
			src.x = (float) ((index % 12) - 1) * 16;
			src.y = (float) (index / 12) * 16;
			dest.x = (column * dest.w);
			dest.y = (row * dest.h);
			SDL_RenderTexture(Game::renderer, tileSet, &src, &dest);
		}
	}
	*/

	for (int row = 0; row < CHUNK_SIZE; row++) {
		for (int column = 0; column < CHUNK_SIZE; column++) {
			int index = level.getTile(row, column);
			dest.x = (row * dest.w);
			dest.y = (column * dest.h);
			if(index > 0) tileSet.RenderTile(index - 1, dest); // -1 because 0 = no tile and 1 = first tile (so index [0])
		}
	}
}
