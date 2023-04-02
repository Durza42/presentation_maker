#include "Game.h"
#include <iostream>

#ifndef __WIN__
int main()
#else
int main(int argc, char** argv)
#endif
{
    Game game;
    game.main_loop();

    return EXIT_SUCCESS;
}
