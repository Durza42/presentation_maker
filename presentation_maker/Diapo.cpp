#include "Diapo.h"

/**
 * @brief Construct a new Global_presentation::Global_presentation object
 */
Diapo::Diapo()
{

}

/**
 * @brief Construct a new Diapo:: Diapo object with one slide par `image_path`
 * 
 * @param Renderer the renderer of the associated window
 * @param image_paths a vector with the path of every image. The diapo will be initialized with as many slides as there is paths.
 */
Diapo::Diapo(SDL_Renderer* Renderer, std::vector<std::string> const& image_paths)
{
    for(std::string const& it: image_paths)
        load(Renderer, it);
}

/**
 * @brief adds the image designed by image_path at the end of the slide vector
 * 
 * @param Renderer the renderer of the associated window
 * @param image_path the path of the new image.
 * @note The new slide will be added at the end of the slide vector.
 */
void Diapo::load(SDL_Renderer* Renderer, std::string const& image_path)
{
    m_slides.push_back(Slide(Renderer, image_path));
}

/**
 * @brief Start and show the first diapo
 * @details Shows the first diapo, and then launch the rest of the diapo
 * @param Renderer the renderer of the associated window
 */
void Diapo::start(SDL_Renderer* Renderer)
{
    m_slides.front().show(Renderer);
}

