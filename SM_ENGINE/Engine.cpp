#include "Engine.h"
#include <iostream>
#include "Position.h"
#include "Sprite.h"
#include "Entity.h"

Engine::Engine() : quit(false)
{
	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << "Unable to init SDL:" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	//Create a window
	window = SDL_CreateWindow(
		"Engine", //Window title
		SDL_WINDOWPOS_CENTERED, //Center window horizontally
		SDL_WINDOWPOS_CENTERED, //Center window vertically
		800, //Width
		600, //Height
		NULL //Optional flags
		);
	if (window == nullptr)
	{
		std::cerr << "Unable to Create Window:" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	renderingSystem = new RenderingSystem(window);
}
Engine& Engine::getInstance(){
	static Engine instance;//Guaranteed to be created and destroyed properly.
						   //Lazily Instantiated on first use.
	return instance;
}
void Engine::start()
{
	Entity e = Entity::create(); 
	std::cout << "Entity e's Component Mask: " << e.getComponentMask() << std::endl;
	e.addComponent<Position>();
	std::cout << "Entity e's Component Mask: " << e.getComponentMask() << std::endl; 
	e.addComponent<Sprite>();
	std::cout << "Entity e's Component Mask after: " << e.getComponentMask() << std::endl;
	while (!quit){
		update();
	}
}
void Engine::update()
{
	//Check for SDL Events (Mouse, Keyboard, Gamepad, OS Messages, etc)
	SDL_Event e;
	while (SDL_PollEvent(&e) != NULL)
	{
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
		renderingSystem->update();
	}
}
Engine::~Engine()
{
	//Destroy the window
	SDL_DestroyWindow(window);
	//Shut Down SDL
	delete renderingSystem;
	SDL_Quit();
}
