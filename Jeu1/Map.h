#pragma once

#include "Game.h"
#include "TextureManager.h"
#include <vector>
#include <bitset>
#include <iostream>

#define CHUNK_SIZE 32

class Tile
{
public:
	SDL_FRect pos; // Tile position in tile set

	Tile(float x_ = 0, float y_ = 0, float w_ = 0, float h_ = 0)
	{
		pos.x = x_; pos.y = y_;
		pos.w = w_; pos.h = h_;
	}
};

class TileSet
{
public:
	SDL_Texture* texture; // tile set texture
	std::vector<Tile> tiles; // one Tile object per tile in the tile set

	// TileSet() :texture(nullptr) {}
	TileSet()
		:texture(nullptr)
	{
		texture = TextureManager::LoadTexture("assets/TrapmoorTileset_v03.png");
		SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST); // to avoid pixel approximation, smoother result
		
		for (int i = 0; i < 96; i++) {
			tiles.emplace_back(
				(float)(i % 12) * 16, // Peut etre ((i%12) - 1) * 16
				(float)(i / 12) * 16, // i/12 => quotient de la division euclidienne
				16, 16);
		}
	}
	~TileSet()
	{
		SDL_DestroyTexture(texture);
	}

	void RenderTile(int index, const SDL_FRect& dest)
	{
		SDL_RenderTexture(Game::renderer, texture, &tiles[index].pos, &dest);
	}
};

class Level
{
private :
	std::vector<uint8_t> tiles; // 0 = no tile, 1 = first tile (= index [0])
	std::bitset<CHUNK_SIZE * CHUNK_SIZE> collision; // 0 = no collision ; 1 = collision

public:
	//Chunk() : tiles{0}, collision{0} {}
	Level()
	{
		tiles = {
		29,16,29,70,70,29,29,29,69,70,29,29,70,29,29,29,29,29,15,59,59,33,47,33,48,48,59,36,23,23,53,53,
		29,29,29,29,29,16,29,29,70,29,29,29,29,29,29,29,15,28,30,33,33,47,47,47,33,48,48,59,36,36,53,53,
		70,29,29,29,29,29,29,29,29,29,29,29,29,16,29,29,15,33,33,47,47,33,33,33,33,33,48,48,59,59,53,53,
		29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,15,33,33,33,47,47,33,33,33,33,33,48,48,48,52,53,
		28,29,29,69,29,15,29,29,29,15,29,29,29,29,70,28,30,33,33,33,33,47,33,58,58,33,33,33,33,48,48,52,
		47,27,28,28,28,29,70,29,29,29,29,29,18,28,30,33,33,33,33,47,47,47,47,33,58,58,33,33,33,33,33,33,
		47,47,33,33,18,70,29,15,29,29,70,29,30,33,33,58,58,33,47,47,47,47,47,47,47,33,33,58,58,33,33,47,
		47,58,58,33,27,28,29,29,16,29,29,15,33,33,33,58,58,58,47,47,47,47,47,47,47,47,33,58,33,47,47,47,
		47,47,58,47,33,58,27,28,28,28,28,30,33,33,58,58,33,58,58,47,47,47,47,47,47,47,47,47,47,47,47,47,
		33,47,47,47,47,33,58,33,58,58,33,33,33,33,33,33,33,47,58,47,47,47,47,47,47,47,47,47,47,47,47,47,
		57,33,33,47,47,47,58,58,33,47,47,33,33,33,33,33,33,58,58,47,47,47,47,47,47,47,47,47,47,47,47,47,
		57,57,33,33,47,47,47,58,58,47,47,47,47,33,58,58,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,
		57,57,33,33,47,47,47,47,58,58,47,58,58,58,58,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,40,40,
		57,33,33,33,47,47,47,47,47,58,58,47,47,47,47,47,47,47,47,47,47,47,47,33,58,47,47,47,47,40,41,41,
		33,33,33,47,47,47,47,47,33,33,33,33,47,47,47,47,47,47,47,47,47,47,33,33,33,58,58,47,40,41,41,41,
		33,33,33,47,47,47,47,33,33,33,33,33,47,47,47,47,47,47,47,47,47,33,33,33,33,33,33,40,41,41,41,41,
		5,4,5,4,5,5,4,4,5,4,5,4,4,5,6,47,58,3,4,4,5,4,6,33,33,33,40,41,41,41,41,41,
		29,29,16,29,16,29,29,15,15,29,16,70,29,29,18,48,59,15,29,29,29,29,15,59,59,40,41,41,41,41,41,41,
		29,15,29,29,15,29,16,29,29,16,69,16,29,29,15,23,23,15,15,29,18,29,18,6,23,41,41,41,41,41,41,41,
		29,29,29,18,69,15,29,29,29,29,15,29,29,29,15,11,12,15,70,29,29,29,29,15,12,41,41,41,41,41,41,41,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 
		};
		
		collision = 0;
		setCollision(0, 0, true);

	}

	uint8_t getTile(int x, int y) const { return tiles[y * CHUNK_SIZE + x]; }
	void setTile(int x, int y, int val) { tiles[y * CHUNK_SIZE + x] = val; }
	bool getCollision(int x, int y) const // collision[0] is the far right bit istead of left, so we need to inbvert x and y
	{
		x = (CHUNK_SIZE - 1) - x;
		y = (CHUNK_SIZE - 1) - y;

		return collision[y * CHUNK_SIZE + x];
	}
	void setCollision(int x, int y, bool state)
	{
		x = (CHUNK_SIZE - 1) - x;
		y = (CHUNK_SIZE - 1) - y;

		collision.set(y * CHUNK_SIZE + x, state);
	}
};

class Map
{
private:
	//std::vector<std::vector<int>> mapTab;
	//SDL_Texture* tileSet;
	TileSet tileSet;
	Level level;

public:
	// Constructors & Destructor

	Map();
	~Map();

	// Methods

	void loadMap();
	void render(const int& tileNumberWidth, const int& tileNumberHeigth);
};

