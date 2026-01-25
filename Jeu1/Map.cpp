#include "Map.h"
#include "TextureManager.h"
#include <iostream>

Map::Map() 
	:IDmap()
{
	
}

Map::~Map() {
	
}


void Map::loadMap()
{
	// Assets loading
	//tileSet = TextureManager::LoadTexture("assets/TrapmoorTileset_v03.png"); // Probably load once at beggining of level
	//SDL_SetTextureScaleMode(tileSet, SDL_SCALEMODE_NEAREST); // to avoid pixel approximation, smoother result

	// Map loading
	/*
	IDmap = {
		{29,16,29,70,70,29,29,29,69,70,29,29,70,29,29,29},
		{29,29,29,29,29,16,29,29,70,29,29,29,29,29,29,29},
		{70,29,29,29,29,29,29,29,29,29,29,29,29,16,29,29},
		{29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29},
		{28,29,29,69,29,15,29,29,29,15,29,29,29,29,70,28},
		{47,27,28,28,28,29,70,29,29,29,29,29,18,28,30,33},
		{47,47,33,33,18,70,29,15,29,29,70,29,30,33,33,58},
		{47,58,58,33,27,28,29,29,16,29,29,15,33,33,33,58},
		{47,47,58,47,33,58,27,28,28,28,28,30,33,33,58,58},
		{33,47,47,47,47,33,58,33,58,58,33,33,33,33,33,33},
		{57,33,33,47,47,47,58,58,33,47,47,33,33,33,33,33},
		{57,57,33,33,47,47,47,58,58,47,47,47,47,33,58,58},
		{57,57,33,33,47,47,47,47,58,58,47,58,58,58,58,47},
		{57,33,33,33,47,47,47,47,47,58,58,47,47,47,47,47},
		{33,33,33,47,47,47,47,47,33,33,33,33,47,47,47,47},
		{33,33,33,47,47,47,47,33,33,33,33,33,47,47,47,47}
	};
	*/
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
			int index = IDmap.getTile(row, column);
			dest.x = (row * dest.w);
			dest.y = (column * dest.h);
			if(index > 0) tileSet.RenderTile(index - 1, dest); // -1 because 0 = no tile and 1 = first tile (so index [0])
		}
	}
}
