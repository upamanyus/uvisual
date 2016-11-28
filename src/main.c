#include <stdio.h>
#include <stdbool.h>
#include "uvisual_window.h"
#include "GL/gl.h"

int main(int argc, char **argv)
{
	puts("Initializing SDL system");
	int ret;
	ret = uvisual_initialize();
	if (ret < 0)
	{
		return -1;
	}

	window_t *win = uvisual_window_create("Hello, world!",
	                                      SDL_WINDOWPOS_UNDEFINED,
	                                      SDL_WINDOWPOS_UNDEFINED,
	                                      680,
	                                      400
	                                      );
	if (win == NULL)
	{
		puts("Window not created");
		return -1;
	}
	glViewport(0, 0, 680, 400);
	SDL_Delay(1.0);
	bool quit = false;
	while (quit == false)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		uvisual_window_render(win);
	}
	uvisual_window_delete(win);

	uvisual_quit();
	puts("Quitting");
	return 0;
}
