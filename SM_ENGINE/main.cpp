#include <SDL.h>
#include <iostream>
#include "Engine.h"
int main(int argc, char* argv[]){
	Engine::getInstance().start();
	return EXIT_SUCCESS;
}