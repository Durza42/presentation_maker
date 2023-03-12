#include "error.h"

#include "../include/SDL2/SDL.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief use SDL_LogCritical to log custom message
 * 
 * @param app_msg the custom message; a new line followed by the result of `SDL_GetError()` will be added.
 */
void Error::log_Critical(std::string const&& app_msg)
{
    std::string errmsg { app_msg + "\n" + SDL_GetError() };
    SDL_LogCritical(0, errmsg.c_str());
    throw std::runtime_error(errmsg);
}
