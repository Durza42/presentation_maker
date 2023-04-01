#include "Diapo.h"
#include "Loader.h"
#include "error.h"

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
Diapo::Diapo(SDL_Renderer* Renderer, std::string const& params_path)
{
    load(Renderer, params_path);
}


Diapo::Diapo(SDL_Renderer* Renderer, Diapo_info const& infos)
{
    load(Renderer, infos);
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
    load(Renderer, Loader::load(image_path));
}

/**
 * @brief set the diaporama to the parameters defines in `infos`
 * 
 * @param Renderer the renderer of the associated window
 * @param infos the Diapo_info description of the diaporama
 */
void Diapo::load(SDL_Renderer* Renderer, Diapo_info const& infos)
{
    for(auto slide : infos.slides)
        m_slides.push_back(Slide(Renderer, slide));
}

/**
 * @brief Start and show the first diapo
 * @details Shows the first diapo, and then launch the rest of the diapo
 * @param Renderer the renderer of the associated window
 */
void Diapo::start(SDL_Renderer* Renderer)
{
    if(m_slides.empty())
        Error::log_Error("cannot show first slide: m_slides is empty.");

    m_slides.front().show(Renderer);
    m_iCurrent_slide = 0;
}
