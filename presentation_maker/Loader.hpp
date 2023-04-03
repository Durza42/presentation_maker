#include <string>
#include <sstream>

namespace Loader
{
    /**
     * @brief returns the first integer of the first line of the `src` std::string. 
     * @warning It will remove the first line from the given string!
     * 
     * @param src a reference to the text to analyse
     * @return [int] the first integer of the first line
     */
    template <typename T>
    inline const T get_first_entity(std::string& src)
    noexcept
    {
        // TODO: might be more efficient...

        std::istringstream ss { src };

        T ret;
        ss >> ret;

        src.clear();
        std::string line;

        while(getline(ss, line))
            src += line + "\n";

        return ret;
    }
}
