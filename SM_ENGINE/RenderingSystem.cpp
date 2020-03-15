#include "RenderingSystem.h"
#include "Entity.h"
#include "Position.h"
#include "Sprite.h"

RenderingSystem::RenderingSystem(SDL_Window* window)
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cerr << "Unable to Create SDL Renderer:" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	componentMask = Position::getMask() | Sprite::getMask();
}

RenderingSystem::~RenderingSystem()
{
	SDL_DestroyRenderer(renderer);
}

void RenderingSystem::update()
{
	//Set the "Clear Screen" colour to Magenta (RBGA)
	SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
	//Clear screen
	SDL_RenderClear(renderer);
	for (Entity& entity : Entity::getEntityList())
	{
		if ((entity.getComponentMask() & componentMask) == componentMask)
		{
			Position& position = entity.getComponent<Position>();
			Sprite& sprite = entity.getComponent<Sprite>();
		}
	}
	//Update screen
	SDL_RenderPresent(renderer);
}