#include "Game.h"
#include "Map.h"
#include "Components.h"
#include "Collision.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Manager manager;
auto& player = manager.addEntity("Player");
auto& wall = manager.addEntity("Wall");

Game::Game(const char* title, int tileNumberW, int tileNumberH)
	:running(false), window(nullptr), tileNumberWidth(tileNumberW), tileNumberHeigth(tileNumberH)
{
	tileWidth = tileHeigth = 32;

	if (SDL_Init(SDL_INIT_VIDEO)) {
		// Window initialisation
		window = SDL_CreateWindow(title, tileNumberWidth * tileWidth, tileNumberHeigth * tileHeigth, SDL_WINDOW_RESIZABLE); //  add SDL_WINDOW_FULLSCREEN flag for full screen  
		if (!window) {
			// SDL_GetError()
			std::cout << "WINDOW CREATION FAILED" << std::endl;
		}
		std::cout << "Window created" << std::endl;

		// Renderer initialisation
		renderer = SDL_CreateRenderer(window, nullptr); // specific renderer can be specified in place of nullptr
		if (!renderer) {
			// SDL_GetError()
			std::cout << "RENDERER CREATION FAILED" << std::endl;
		}
		SDL_SetRenderLogicalPresentation(renderer, tileNumberWidth * tileWidth, tileNumberHeigth * tileHeigth, SDL_LOGICAL_PRESENTATION_LETTERBOX);
		SDL_SetRenderDrawColor(renderer, 255, 180, 180, 255);
		std::cout << "Renderer created" << std::endl;

		running = true;

		// Map loading
		map = std::make_unique<Map>();
		map->loadMap();

		// ECS Implementation
		player.addComponent<TransformComponent>();
		player.addComponent<SpriteComponent>("assets/skeleton.png", 32., 24.);
		player.addComponent<KeyboardController>();
		player.addComponent<ColliderComponent>();

		wall.addComponent<TransformComponent>(150, 150);
		wall.addComponent<SpriteComponent>("assets/skeleton.png", 32., 24.);
		wall.addComponent<ColliderComponent>();
	}
}

Game::~Game() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::HandleEvents() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_EVENT_QUIT:
		running = false;
		break;

	default:
		break;
	}
}

void Game::Update() {
	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<ColliderComponent>().collider, wall.getComponent<ColliderComponent>().collider))
	{
		if (player.getComponent<TransformComponent>().scale == 3) player.getComponent<TransformComponent>().scale = 5;
		else player.getComponent<TransformComponent>().scale = 3;

		std::cout << "COLLISION !!! player scale : " << player.getComponent<TransformComponent>().scale << std::endl;
	}
}

void Game::Render() {
	SDL_RenderClear(renderer); // Clear the rendering target

	map->render(tileNumberWidth, tileNumberHeigth);
	manager.render();

	SDL_RenderPresent(renderer); // Update the screen
}