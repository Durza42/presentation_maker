#include <SDL2/SDL.h>
#include <string>

#define WINDOW_W 900
#define WINDOW_H 700
#define WINDOW_TITLE "presentation maker"

/**
 * @brief basic SDL2 Widgets manager
 * @details This class is supposed to store the basic SDL2 Widgets: window / renderer, and make their use easier.
 */
class Context
{
   public:

    Context(const std::string&& title=WINDOW_TITLE, const int&& w=WINDOW_W, const int&& h=WINDOW_H);

    constexpr SDL_Window* get_window() const noexcept;
    constexpr SDL_Renderer* get_renderer() const noexcept;

   protected:

    SDL_Window* Window;
    SDL_Renderer* Renderer;
};