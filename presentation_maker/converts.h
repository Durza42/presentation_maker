#include <string>
#include <SDL2/SDL.h>

namespace std
{
    inline string to_string(SDL_Rect __val)
    {
        return "{" + to_string(__val.x) + "," + to_string(__val.y) + "; " + to_string(__val.w) + "*" + to_string(__val.h) + "}";
    }
}
