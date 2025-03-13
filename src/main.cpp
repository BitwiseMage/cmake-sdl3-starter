#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

constexpr const char* SDL_WINDOW_TITLE = "cmake-sdl3-starter";
constexpr int SDL_WINDOW_WIDTH = 1600;
constexpr int SDL_WINDOW_HEIGHT = 900;
constexpr SDL_WindowFlags SDL_WINDOW_FLAGS = 0;

int main(int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Video initialization failed: %s", SDL_GetError());
        return -1;
    }

    SDL_Window* sdl_window = SDL_CreateWindow(SDL_WINDOW_TITLE, SDL_WINDOW_WIDTH, SDL_WINDOW_HEIGHT, SDL_WINDOW_FLAGS);
    if (sdl_window == nullptr)
    {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return -1;
    }

    SDL_Surface* sdl_screen_surface = SDL_GetWindowSurface(sdl_window);
    SDL_FillSurfaceRect(sdl_screen_surface, nullptr, SDL_MapSurfaceRGB(sdl_screen_surface, 70, 70, 70));
    SDL_UpdateWindowSurface(sdl_window);

    SDL_Event sdl_event;
    SDL_zero(sdl_event);

    while (SDL_PollEvent(&sdl_event) || true)
    {
        if (sdl_event.type == SDL_EVENT_QUIT)
        {
            break;
        }
    }

    SDL_DestroySurface(sdl_screen_surface);
    sdl_screen_surface == nullptr;

    SDL_DestroyWindow(sdl_window);
    sdl_window = nullptr;

    SDL_Quit();
    return 0;
}