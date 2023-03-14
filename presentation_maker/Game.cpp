#include "Game.h"

Game::Game()
{
    
}

void Game::main_loop()
{
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
    SDL_Delay(1000);
}