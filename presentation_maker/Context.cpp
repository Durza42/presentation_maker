#include "Context.h"
#include "error.h"
#include <iostream>
#include <SDL2/SDL_image.h>

/**
 * @brief Construct a new Context::Context object; Initialize SDL2, create window and renderer.
 * @param title the title of the window.
 * @param w the weigth of the window.
 * @param h the heigth og the window.
 * @exception if an initialization fails, log related error message with Error::log_Critical; this throw a std::runtime_error exception.
 * @note renderer will be created as SDL_RENDERER_TARGETTEXTURE.
 */
Context::Context(const std::string&& title, const int&& w, const int&& h)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        Error::log_Critical("error initializing SDL2.");

    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) <= 0)
        Error::log_Critical("error initializing SDL2_image.");

    Window = SDL_CreateWindow(
        title.c_str(),
        0, 0,
        w, h,
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
