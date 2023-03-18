#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

/**
 * @brief stores one silde of the presentation
 */
class Slide
{
   public:

    Slide();
    Slide(SDL_Renderer* Renderer, std::string const& image_path);

    void load(SDL_Renderer* Renderer, std::string const& image_path);

    void show(SDL_Renderer* Renderer) noexcept;

   private:

    /// @brief the image of this slide
    SDL_Texture* m_image = nullptr;
};