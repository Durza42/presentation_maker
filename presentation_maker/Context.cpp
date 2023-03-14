#include "Context.h"
#include "error.h"
#include <iostream>

Context::Context()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        Error::log_Critical("error initializing SDL.");

    Window = SDL_CreateWindow(
        "presentation maker",
        0, 0,
        800, 600,
        SDL_WINDOW_SHOWN
    );
    if(!Window)
        Error::log_Critical("error initializing SDL_Window.");

    Renderer = SDL_CreateRenderer(
        Window,
        -1,
        SDL_RENDERER_TARGETTEXTURE
    );
    if(!Renderer)
        Error::log_Critical("error initializing SDL_Renderer.");
}

constexpr SDL_Window* Context::get_window() const noexcept
{
    return Window;
}

constexpr SDL_Renderer* Context::get_renderer() const noexcept
{
    return Renderer;
}
