#include "../include/SDL2/SDL.h"

#define WINDOW_W 900
#define WINDOW_H 700

class Context
{
   public:

    Context();

   private:

    SDL_Window* Window;
    SDL_Renderer* Renderer;
};