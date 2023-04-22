#ifndef _DIAPO_H
 #define _DIAPO_H

 #include <SDL2/SDL.h>
 #include <vector>
 #include <string>

 #include "Slide.h"

/**
 * @brief used to describe a Diapo object
 * @note it is designed to be used as a function return, because the Slide_info class only store the image's path, instead of the whole image for Slide
 */
struct Diapo_info
{
    /// @brief number of diapos in the diaporama
    int nb_diapos = 0;

    /// @brief description of all the slides of the presentation, in presentation order
    std::vector<Slide_info> slides;
};


/**
 * @brief stores the diaporama itself
 */
class Diapo
{
   public:

    Diapo();
    Diapo(SDL_Renderer* Renderer, std::string const& params_path);
    Diapo(SDL_Renderer* Renderer, Diapo_info const& infos);

    void load(SDL_Renderer* Renderer, std::string const& image_path);
    void load(SDL_Renderer* Renderer, Diapo_info const& infos);

    void start(SDL_Renderer* Renderer);
    bool next(SDL_Renderer* Renderer);
    bool previous(SDL_Renderer* Renderer);

    constexpr
    bool is_in_transition()
    noexcept;

    void continue_slide_change();

   private:

    /// @brief all the slides of the presentation, in presentation order
    std::vector<Slide> m_slides;

    /// @brief indice of the currently shown slide
    std::vector<Slide>::size_type m_iCurrent_slide;

    /// @brief true if the diapo is changing from a diapo to another
    bool m_is_in_transition = false;
};

#endif