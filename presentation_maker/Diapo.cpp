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
 *
 * @exception std::runtime_error if the `m_slide` member is empty, i.e. if the diapo does not have any loaded slide
 * 
 * @param Renderer the renderer of the associated window
 */
void Diapo::start(SDL_Renderer* Renderer)
{
    if(m_slides.empty())
        Error::log_Error("cannot show first slide: m_slides is empty.");

    m_iCurrent_slide = 0;
    m_slides[m_iCurrent_slide].show(Renderer);
}

#include <iostream>
/**
 * @brief pass to the next diapositive and print it into the renderer
 * 
 * @param Renderer the renderer of the associated window
 *
 * @exception std::runtime_error if the `m_slide` member is empty, i.e. if the diapo does not have any loaded slide
 * 
 * @return true if the change has been done successfuly
 * @return false if the show is already in its last diapo
 */
bool Diapo::next(SDL_Renderer* Renderer)
{
    if(m_slides.empty())
        Error::log_Error("cannot show next slide: m_slides is empty.");

    if(m_iCurrent_slide + 1 == m_slides.size())
        return false;

TODO: // make animation

    ++m_iCurrent_slide;
    m_slides[m_iCurrent_slide].show(Renderer);
    return true;
}

/**
 * @brief get back to the previous diapositive and print it into the renderer
 * 
 * @param Renderer the renderer of the associated window
 *
 * @exception std::runtime_error if the `m_slide` member is empty, i.e. if the diapo does not have any loaded slide
 * 
 * @return true if the change has been done successfuly
 * @return false if the show is already in its first diapo
 */
bool Diapo::previous(SDL_Renderer* Renderer)
{
    if(m_slides.empty())
        Error::log_Error("cannot show next slide: m_slides is empty.");

    if(m_iCurrent_slide == 0)
        return false;

    --m_iCurrent_slide;
    m_slides[m_iCurrent_slide].show(Renderer);
    return true;
}
