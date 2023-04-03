#include "Game.h"
#include <iostream>

/**
 * @brief Construct a new Game:: Game object
 * @note if the requested images are not correct, the program will brutaly end with an error message.
 */
Game::Game()
{
    try
    {
        m_diapo.load(Renderer, "hello_world");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " | cannot continue; abort" << '\n';
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief starts the diaporama
 */
void Game::init()
{
    SDL_RenderClear(Renderer);

    m_diapo.start(Renderer);

    update_screen();
}

/**
 * @brief the main loop of the process
 * @details from here will be managed everything, from user actions to window refresh.
 */
void Game::main_loop()
{
    init();

    while(true)
    {
        if(manage_events())
            update_screen();

        SDL_Delay(50);
    }
}


/**
 * @brief does the action in response to the events
 * 
 * @return true if the events led to actions that need an update of the window
 * @return false if there was no important events or if the changes can be done without refreshing the window
 */
bool Game::manage_events()
{
    if(m_events.update())
    {
        if(m_events.request_close())
            exit(EXIT_SUCCESS);

        if(m_events.key_is_pressed(SDL_SCANCODE_RIGHT))
            return m_diapo.next(Renderer);

        if(m_events.key_is_pressed(SDL_SCANCODE_LEFT))
            return m_diapo.previous(Renderer);

        return false;
    }
    return false;
}

/**
 * @brief refresh the window and makes the renderer available for new updates
 */
void Game::update_screen()
{
    SDL_RenderPresent(Renderer);  
    SDL_RenderClear(Renderer);
}
