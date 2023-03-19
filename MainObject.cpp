#include "MainObject.h"

MainObject::MainObject()
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = 0;
	rect_.h = 0;
	x_val = 0;
	y_val = 0;
}

MainObject::~MainObject()
{
	;
}

void MainObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val -= HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_DOWN:
			y_val += HEIGHT_MAIN_OBJECT / 4;
			break;
		case SDLK_RIGHT:
			x_val -= WIDTH_MAIN_OBJECT / 4;
			break;
		case SDLK_LEFT:
			x_val += WIDTH_MAIN_OBJECT / 4;
			break;
		default:
			break;
		}
	}
	else if (events.type == SDL_KEYUP)
	{
		
	}
	else if (events.type == SDL_MOUSEBUTTONDOWN)
	{

	}
	else if (events.type == SDL_MOUSEBUTTONUP)
	{

	}
}

void MainObject::HandleMove()
{
	rect_.x += x_val;
	if (rect_.x < 0 || rect_.x + WIDTH_MAIN_OBJECT > SCREEN_WIDTH)
	{
		rect_.x -= x_val;
	}
	rect_.y += y_val;
	if (rect_.y < 0 || rect_.y + HEIGHT_MAIN_OBJECT > SCREEN_HEIGHT - 200)
	{
		rect_.y -= y_val;
	}
}