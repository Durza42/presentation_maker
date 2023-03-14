#include "Context.h"
#include "error.h"
#include <iostream>

Context::Context()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        Error::log_Critical("error initializing SDL");

    Window = SDL_CreateWindow(
        "presentation maker",
        0, 0,
        800, 600,
        SDL_WINDOW_SHOWN
    );
//    if(!Window)
        Error::log_Critical("error initializing SDL_Window");

    SDL_Delay(1000);
}
