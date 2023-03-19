#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#define SDL_MAIN_HANDLED
#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Window* window = NULL;
static SDL_Surface* screen_surface = NULL;
static SDL_Surface* background = NULL;
static SDL_Event event;

namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp();
}

#endif // !COMMON_FUNCTION_H_
