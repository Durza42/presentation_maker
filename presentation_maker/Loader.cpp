#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include "Diapo.h"
#include "Loader.h"
#include "Loader.hpp"
#include "Context.h"
#include "converts.h"

/**
 * @brief the raw content of the specified file
 * 
 * @param path the path of the file to read
 * @return [std::string] raw content of the file
 */
std::string Loader::get_file_text(std::string const& path)
noexcept
{
    std::ifstream file { path };

    std::string ret;
    std::string line;
    while(std::getline(file, line))
        ret += line + "\n";

    return ret;
}

/**
 * @brief removes all characters after the "~~" delimiter (including them)
 * 
 * @param text a const reference to the text from which the comments must be deleted. It will be modified itself.
 */
std::string Loader::remove_comments(std::string const& text)
noexcept
{
    // TODO: check algorithm again

    std::string const comment_introcucer { "~~" };

    std::istringstream ss { text };
    std::vector<std::string> vText;

    std::string line;
    while(std::getline(ss, line))
        vText.push_back(line);

    for(auto& line : vText)
    {
        auto first_occur = std::search(
            line.begin(), line.end(),
            comment_introcucer.begin(), comment_introcucer.end()
        );
        line.replace(
            first_occur, line.end(),
            {}
        );
    }

    std::string ret;
    for(auto it : vText)
        ret += it + "\n";

    return ret;
}

/**
 * @brief split the `file` into an array of diapos.
 * Every case of the std::vector will be a part of the file which contains specifications for its diapo.
 * @note the function does NOT load the diapos, it only split the std::string into a std::vector of std::string, each std::string describing a diapo.
 * 
 * @param file a reference to the text of the file
 * @return [std::vector<std::string>] an array containing the std::string description of every diapositives
 */
std::vector<std::string> Loader::split_in_diapos(std::string& file)
noexcept
{
    const char separator = '>';
    std::vector<std::string> ret;

    auto last = file.begin();
    auto next = last;

    while(next != file.end())
    {
        next = find(last + 1, file.end(), separator);
        ret.push_back(file.substr(last - file.begin() + 1, next - last - 2));
        last = next;
    }

    return ret;
}

/**
 * @brief create a Slide_info object from its description in text format (as in param file)
 * 
 * @param src the source text from which the informations need to be extracted
 * @return [Slide_info] the Slide_info object obtained
 */
Slide_info Loader::load_slide(std::string const& src)
{
    std::istringstream ss { src };

    Slide_info ret;

    if(src.length() == 0)
        return ret;

    ss >> ret.img_name;

    auto read_rect = [&src, &ss](SDL_Rect& rect) -> bool
    {
        std::string tmp_input;
        ss >> tmp_input;

        if(tmp_input == "full")
        {
            rect = {0, 0, 0, 0};
            return false;
        }

        rect.x = std::stoi(tmp_input);
        ss >> rect.y >> rect.w >> rect.h;
        if(rect.h < 0)
        {
            rect.h *= 2;
            rect.h += WINDOW_H;
        }
        if(rect.w < 0)
        {
            rect.w *= 2;
            rect.w += WINDOW_W;
        }
        return true;
    };

    ret.dest_is_set = read_rect(ret.dest);
    ret.src_is_set = read_rect(ret.src);


    int r, g, b;
    ss >> r >> g >> b;
    ret.background.r = r;
    ret.background.g = g;
    ret.background.b = b;
    ret.background.a = 0;

    return ret;
}

/**
 * @brief loads a Diapo from the specified file
 * 
 * @param path the relative or absolute path of the file
 * @return [Diapo_info] a description of the Diapo object described by the file
 */
Diapo_info Loader::load(std::string const& path)
{
    Diapo_info ret { 0, {}, 0 };

    auto plain_text = get_file_text(path + "/.params");
    plain_text = remove_comments(plain_text);

    ret.transition_time_ms = get_first_entity<int>(plain_text);
    ret.nb_diapos = get_first_entity<int>(plain_text);

    auto diapos = split_in_diapos(plain_text);

    for(auto&& it : diapos)
    {
        auto new_slide = load_slide(it);

        if(new_slide.img_name.length() == 0)
            continue;

        new_slide.img_name = path + "/imgs/" + new_slide.img_name;

        ret.slides.push_back(new_slide);
    }

    return ret;
}
