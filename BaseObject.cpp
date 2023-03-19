#include "BaseObject.h"
#include "Common_Function.h"

BaseObject::BaseObject()
{
	rect_.x = 0;
	rect_.y = 0;
	object_ = NULL;
}

BaseObject::~BaseObject()
{
	if (object_ != NULL)
	{
		SDL_FreeSurface(object_);
	}
}

bool BaseObject::LoadIMG(const char* file_name)
{
	object_ = SDLCommonFunc::LoadImage(file_name);
	if (object_ == NULL)
	{
		return false;
	}
	return true;
}

void BaseObject::Show(SDL_Surface* des)
{
	if (object_ != NULL)
	{
		SDLCommonFunc::ApplySurface(object_, des, rect_.x, rect_.y);
	}
}
