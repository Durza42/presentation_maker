#include <SDL2/SDL.h>
#include <vector>
#include "Transition.hpp"

class Transition
{
   public:

    Transition();
    Transition(std::size_t const& transition_precision);

    void begin_transition(SDL_Rect const& previous_src, SDL_Rect const& previous_dest);
    void continue_change();

    constexpr
    bool is_finished()
    noexcept;

   private:

    /// @brief the src rect of the previous slide = the src rect before begining the transition
    SDL_Rect start_src;

    /// @brief the dest rect of the previous slide = the dest rect before begining the transition
    SDL_Rect start_dest;

    /// @brief the src rect to be get after the transition is done.
    SDL_Rect goal_src;

    /// @brief the dest rect to be get after the transition is done.
    SDL_Rect goal_dest;

    /// @brief describes the transition of this slide. See show() for further details.
    std::vector<double> transition_size_change;

    /// @brief -1 if the transition is done. A number in [0; transition_size_change.size()] if not, corresponding to the number of size changes done.
    int id_transition_change = -1;
};

