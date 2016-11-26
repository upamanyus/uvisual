#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
	puts("Initializing SDL system");
	int res = 0;
	res = SDL_Init(SDL_INIT_VIDEO);
	if (res == -1)
	{
		puts("[ERROR]: Unable to initialize SDL");
		return 1;
	}
	SDL_Window *window = SDL_CreateWindow("SDL Window", 0, 0, 600, 400, 0);
	if (window == NULL)
	{
		puts("[ERROR]: Unable to create SDL window");
		SDL_Quit();
		return 2;
	}

	SDL_Delay(2000);

	SDL_Quit();
	puts("Quitting");
	return 0;
}
