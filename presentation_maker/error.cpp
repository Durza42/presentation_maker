#include "error.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <stdexcept>

/**
 * @brief use SDL_LogCritical to log custom message
 * @param app_msg the custom message; a new line followed by the result of `SDL_GetError()` will be added.
 * @exception std::runtime_error will be thrown
 */
void Error::log_Critical(std::string const&& app_msg)
{
    std::string errmsg { app_msg + "\n" + SDL_GetError() };
    SDL_LogCritical(0, "%s", errmsg.c_str());
    throw std::runtime_error(errmsg);
}


/**
 * @brief use SDL_LogError to log custom message
 * @param app_msg the custom message; a new line followed by the result of `SDL_GetError()` will be added.
 * @exception std::runtime_error will be thrown
 */
void Error::log_Error(std::string const&& app_msg)
{
    std::string errmsg { app_msg + "\n" + SDL_GetError() };
    SDL_LogError(0, "%s", errmsg.c_str());
    throw std::runtime_error(errmsg);
}


/**
 * @brief use SDL_LogWarn to log custom message
 * @param app_msg the custom message; a new line followed by the result of `SDL_GetError()` will be added.
 */
void Error::log_Warning(std::string const&& app_msg) noexcept
{
    std::string errmsg { app_msg + "\n" + SDL_GetError() };
    SDL_LogWarn(0, "%s", errmsg.c_str());
}
