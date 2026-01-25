#pragma once
#include <memory>
#include <SDL3/SDL.h>

class Map; // forward declaration of Map, avoid circular dependency

class Game
{
private:
	bool running;
	int tileWidth, tileHeigth, tileNumberWidth, tileNumberHeigth;
	SDL_Window* window;
	std::unique_ptr<Map> map;

public:
	static SDL_Renderer* renderer; // unique renderer for the game, accessible by all, avoid many local pointer creations
	static SDL_Event event;

	// Constructors & Destructor

	/// <param name="title"> title of the window </param>
	/// <param name="tileNumberWidth"> Number of tiles in width </param>
	/// <param name="tileNumberHeigth"> Number of tiles in heigth </param>
	Game(const char* title, int tileNumberW, int tileNumberH); // Constructor
	~Game(); // Destructor

	// Getters & Setters

	bool IsRunning() { return running; }

	// Methods

	void HandleEvents();
	void Update();
	void Render();
};