#ifndef _SLIDE_H
 #define _SLIDE_H

 #include <SDL2/SDL.h>
 #include <SDL2/SDL_image.h>
 #include <string>

/**
 * @brief used to describe a single slide
 * @note it is mainly used returned by a function, because it only store the image's path, instead of the whole image
 */
struct Slide_info
{
    /// @brief name of the image shown by this slide
    std::string img_name;

    /// @brief true is this slide has set `src` up, false otherwise
    bool src_is_set = false;

    /// @brief the part of the image (`img_name`) which will be shown in the screen
    SDL_Rect src;

    /// @brief true is this slide has set `dest` up, false otherwise
    bool dest_is_set = false;

    /// @brief the part of the windown which will be filled with the image (`img_name`)
    SDL_Rect dest;

    /// @brief color used for the background, if the window does not fill the entire window. Default is black.
    SDL_Color background;
};

/**
 * @brief stores one silde of the presentation
 */
class Slide
{
   public:

    Slide();
    Slide(SDL_Renderer* Renderer, Slide_info info);

    void load(SDL_Renderer* Renderer, std::string const& image_path);

    void show(SDL_Renderer* Renderer);

   private:

    /// @brief the image of this slide
    SDL_Texture* m_image = nullptr;

    /// @brief true is this slide has set `src` up, false otherwise
    bool src_is_set = false;

    /// @brief the part of the image (`img_name`) which will be shown in the screen
    SDL_Rect src;

    /// @brief true is this slide has set `dest` up, false otherwise
    bool dest_is_set = false;

    /// @brief the part of the windown which will be filled with the image (`img_name`)
    SDL_Rect dest;
};

#endif