#include "Common_Function.h"


SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path)
{
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;

    load_image = IMG_Load(file_path.c_str());
    if (load_image != NULL)
    {
        optimize_image = SDL_ConvertSurface(load_image, screen_surface->format, 0);
        SDL_FreeSurface(load_image);
        if (optimize_image != NULL)
        {
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0xFF, 0xFF);
            SDL_SetColorKey(optimize_image, SDL_TRUE, SDL_MapRGB(optimize_image->format, 0, 255, 255));
        }
    }

    return optimize_image;
}

void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}

void SDLCommonFunc::CleanUp()
{
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen_surface);
    SDL_DestroyWindow(window);
}