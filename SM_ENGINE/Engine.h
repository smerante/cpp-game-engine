#pragma once
#include <SDL.h>
#include "RenderingSystem.h"
class Engine
{
private:
	SDL_Window* window;
	bool quit;
	RenderingSystem* renderingSystem;

	Engine();
	~Engine();
	//Don't Implement
	Engine(Engine& copy); //Hide Copy Constructor.
	Engine(Engine&& other); //Hide Move Constructor
	Engine& operator= (Engine& copy); //Hide Assignment Operator.
	
public:
	static Engine& getInstance(void);

	void start(void);
	void update(void);
};

