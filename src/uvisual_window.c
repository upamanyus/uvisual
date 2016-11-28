// Copyright (c) 2016 Upamanyu Sharma

#include "uvisual_window.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>

int
uvisual_initialize()
{
	int ret = 0;
	ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0)
	{
		fprintf(stderr, "[ERROR]: Unable to intialize SDL\n");
		return -1;
	}

	return 0;
}

void
uvisual_quit()
{
	SDL_Quit();
}

window_t*
uvisual_window_create(const char *window_title, int x, int y, int w, int h)
{
	window_t *win = (window_t*)malloc(sizeof(window_t));

	win->sdl_window = SDL_CreateWindow(window_title, x, y, w, h, SDL_WINDOW_OPENGL);
	if (win->sdl_window == NULL)
	{
		fprintf(stderr, "Could not create SDL window. SDL Error \"%s\"\n",
		        SDL_GetError());
		free(win);
		return NULL;
	}

	win->x = x;
	win->y = y;
	win->w = w;
	win->h = h;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	win->gl_context = SDL_GL_CreateContext(win->sdl_window);
	if (win->gl_context == NULL)
	{
		fprintf(stderr, "Could not create GL context\n");
		free(win);
		return NULL;
	}
	glewExperimental = GL_TRUE;
	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		fprintf(stderr, "[ERROR]: Unable to initialize GLEW\n");
		fprintf(stderr, "[ERROR]: Glew error: %s\n", glewGetErrorString(glewError));
		SDL_DestroyWindow(win->sdl_window);
		free(win);
		return NULL;
	}

	return win;
}

void
uvisual_window_delete(window_t *win)
{
	SDL_DestroyWindow(win->sdl_window);
	free(win);
}
