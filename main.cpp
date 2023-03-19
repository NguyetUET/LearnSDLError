#include "Common_Function.h"
#include "MainObject.h"

bool Init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        return false;
    }

    screen_surface = SDL_GetWindowSurface(window);

    return true;
}

SDL_Surface* LoadImage(std::string file_path)
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

void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}

void CleanUp()
{
    SDL_FreeSurface(background);
    SDL_FreeSurface(screen_surface);
    SDL_DestroyWindow(window);
}

int main()
{
    bool is_quit = false;

    if (Init() == false)
    {
        return 1;
    }

    background = SDLCommonFunc::LoadImage("bg2.png");
    if (background == NULL)
    {
        return 1;
    }

    MainObject human_object;
    human_object.SetRect(100, 200);
    bool ret = human_object.LoadIMG("plane80.png");
    if (!ret)
    {
        return 0;
    }

    human_object.Show(screen_surface);
    while (!is_quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(event);
        }
        SDLCommonFunc::ApplySurface(background, screen_surface, 0, 0);
        human_object.Show(screen_surface);
        human_object.HandleMove();
        SDL_UpdateWindowSurface(window);
    }

    SDLCommonFunc::CleanUp();
    SDL_Quit();
    return 0;
}
