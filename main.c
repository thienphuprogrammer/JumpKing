#include "CommonFunction.h"
#include "BaseObject.h"
#include "MainObject.h"

BaseObject g_background;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_windows = SDL_CreateWindow("Game Cpp SDL 2.0",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (g_windows == NULL) success = false;
    else
    {
        g_screen = SDL_CreateRenderer(g_windows, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL) success = false;
        else
        {
            SDL_SetRenderDrawColor(g_screen,
                RENDERER_DRAW_COLOR,
                RENDERER_DRAW_COLOR,
                RENDERER_DRAW_COLOR,
                RENDERER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
            {
                printf("Error: %s\n", IMG_GetError());
                success = false;
            }
        }
    }
    return success;
}

void close()
{
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_windows);
    g_windows = NULL;

    IMG_Quit();
    SDL_Quit();
}

#undef main
int main(int argc, char* argv[]) {

    if (!InitData()) return -1;
  
    bool is_quit = false;
    while (!is_quit)
    {
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
        }

        SDL_SetRenderDrawColor(g_screen, RENDERER_DRAW_COLOR, RENDERER_DRAW_COLOR, RENDERER_DRAW_COLOR, RENDERER_DRAW_COLOR);
        SDL_RenderClear(g_screen);
        SDL_RenderPresent(g_screen);
    }

    close();
    return 0;
}
