#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "Slide.h"

/**
 * @brief stores the diaporama itself
 */
class Diapo
{
   public:

    Diapo();
    Diapo(SDL_Renderer* Renderer, std::vector<std::string> const& image_paths);

    void load(SDL_Renderer* Renderer, std::string const& image_path);
    void start(SDL_Renderer* Renderer);

   private:

    /// @brief all the slides of the presentation, in presentation order
    std::vector<Slide> m_slides;
};
