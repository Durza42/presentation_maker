#include "Slide.h"

#include <string>
#include "error.h"


/**
 * @brief Construct a new Slide:: Slide object
 * @warning this constructor let the m_image attribute set to nullptr!
 */
Slide::Slide()
{

}


/**
 * @brief Construct a new Slide::Slide object with the given image and renderer
 * @exception std::runtime_error exception will be thrown if the image_path is not correct.
 */
Slide::Slide(SDL_Renderer* Renderer, std::string const& image_path)
{
    load(Renderer, image_path);
}

/**
 * @brief loads the image at `image_path`, and store it 
 * 
 * @param Renderer the renderer of the associated window
 * @param image_path the path of the image show when showing the slide
 * @exception std::runtime_error will be thrown if the `image_path` parameter does not design a correct image on the disk.
 */
void Slide::load(SDL_Renderer* Renderer, std::string const& image_path)
{
    m_image = SDL_CreateTextureFromSurface(Renderer, IMG_Load(image_path.c_str()));
    if (!m_image)
    {
        m_image = nullptr;
        Error::log_Error("error loading " + image_path);
    }
}

/**
 * @brief copy the slide's image into the `Renderer`
 * @param Renderer the targeted SDL_Renderer
 * @note if the slide has not be associated to an image, a warning will be printed using Error::log_Warning
 */
void Slide::show(SDL_Renderer* Renderer) noexcept
{
    if(m_image != nullptr)
        SDL_RenderCopy(Renderer, m_image, nullptr, nullptr);
    else
        Error::log_Warning("cannot print nullptr image");
}
