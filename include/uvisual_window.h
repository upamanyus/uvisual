// Copyright (c) 2016 Upamanyu Sharma
#ifndef UVISUAL_H_
#define UVISUAL_H_

#include <SDL2/SDL.h>

typedef struct window {
	SDL_Window *sdl_window;
	SDL_GLContext gl_context;
	int x;
	int y;
	int h;
	int w;
} window_t;

// Initialize all necessary components needed for uvisual to work. This needs to
// be called before any uvisual windows can be created.
// Returns negative if there was an error, 0 otherwise.
int
uvisual_initialize();

// Deinitializes everything initialized by `uvisual_initialize()'.
void
uvisual_quit();

// The x, y, w, h arguments are of the same format given to SDL_CreateWindow(...).
window_t*
uvisual_window_create(const char *window_title, int x, int y, int w, int h);

void
uvisual_window_delete(window_t *win);

void
uvisual_window_render(window_t *win);

#endif // UVISUAL_H_
