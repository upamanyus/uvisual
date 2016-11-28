#include <stdio.h>
#include "uvisual_window.h"

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

	SDL_Delay(2000);

	uvisual_window_delete(win);

	uvisual_quit();
	puts("Quitting");
	return 0;
}
