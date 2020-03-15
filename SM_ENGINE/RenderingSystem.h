#pragma once
#include "ISystem.h"
#include <iostream>
#include <SDL.h>
#include "System.h"

class RenderingSystem :  public System<RenderingSystem>
{
public:
	RenderingSystem(SDL_Window* window);
	~RenderingSystem();

	void update();
private:
	SDL_Renderer* renderer;
};

