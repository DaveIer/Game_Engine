#include "Game.h"
#include <iostream>

std::unique_ptr <Game> game;
const double FRAME_TIME = 1.0 / 60.0; // time between each frame

int main() {
	// Declarations
	game = std::make_unique<Game>("Game", 32, 32);
	uint64_t prevTime = SDL_GetPerformanceCounter();
	uint64_t prevSec = prevTime;
	static const uint64_t COUNTER_FREQUENCY = SDL_GetPerformanceFrequency(), START_COUNT = SDL_GetPerformanceCounter();
	uint16_t fps = 0;

	// Main loop
	while (game->IsRunning()) {
		uint64_t curTime = SDL_GetPerformanceCounter(); // get current ticks
		double timeStep = (double) (curTime - prevTime) / COUNTER_FREQUENCY; // time passed since last frame (seconds)
		prevTime = curTime; // save ticks for next frame

		// Game 
		game->HandleEvents();
		game->Update(); // add timestep
		game->Render();

		// Fps limitation delay
		timeStep = (double)(SDL_GetPerformanceCounter() - curTime) / COUNTER_FREQUENCY; // get time since beginning of frame (seconds)
		if (timeStep < FRAME_TIME) SDL_Delay((uint32_t) ((FRAME_TIME - timeStep) * 1000));

		// Report
		fps++;
		curTime = SDL_GetPerformanceCounter();
		if (curTime >= (prevSec + COUNTER_FREQUENCY)) {
			std::cout << "Time since start : " << (curTime - START_COUNT) / COUNTER_FREQUENCY << " s" << std::endl;
			std::cout << "FPS : " << fps << std::endl;
			fps = 0;
			prevSec = curTime;
		}
	}

	return 0;
}