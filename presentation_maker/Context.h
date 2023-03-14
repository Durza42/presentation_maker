#include <SDL2/SDL.h>

#define WINDOW_W 900
#define WINDOW_H 700

class Context
{
   public:

    Context();

    constexpr SDL_Window* get_window() const noexcept;
    constexpr SDL_Renderer* get_renderer() const noexcept;

   protected:

    SDL_Window* Window;
    SDL_Renderer* Renderer;
};