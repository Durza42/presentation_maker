#include <vector>
#include <string>
#include "Diapo.h"

/**
 * @brief used to loads a diaporama.
 * @details use ::load to get a Diapo object from a .params file.
 */
namespace Loader
{
    Diapo_info load(std::string const& path);

    std::string get_file_text(std::string const& path)
    noexcept;

    std::string remove_comments(std::string const& text)
    noexcept;

    std::vector<std::string> split_in_diapos(std::string& file)
    noexcept;

    Slide_info load_slide(std::string const& src);
};
