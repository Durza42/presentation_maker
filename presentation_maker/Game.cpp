#include "Game.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 */
Game::Game()
{
    m_diapo.load(Renderer, "imgs/boom.jpg");
}

/**
 * @brief the main loop of the process
 * @details from here will be managed everything, from use actions to window refresh.
 * 
 */
void Game::main_loop()
{
    SDL_RenderClear(Renderer);

    m_diapo.start(Renderer);

    SDL_RenderPresent(Renderer);

    SDL_Event event;
    while(true)
        while(SDL_PollEvent(&event))
            if(event.type == SDL_QUIT)
                exit(0);
}

