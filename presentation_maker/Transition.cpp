#include "Transition.h"
#include "Transition.hpp"

Transition::Transition()
{

}

Transition::Transition(std::size_t const& transition_precision) :
            transition_size_change { transition_values(transition_precision) }
{

}

void Transition::begin_transition(SDL_Rect const& previous_src, SDL_Rect const& previous_dest)
{
    goal_src = src;
    src = previous_src;

    goal_dest = dest;
    dest = previous_dest;

    id_transition_change = 0;
}

void Transition::continue_change()
{
    if(id_transition_change < 0)
        return;


}

/**
 * @brief get if the transition has been completly done.
 * 
 * @return true if the current slide is shown at screen
 * @return false if others call to continue_change() are needed
 */
constexpr
bool Transition::is_finished()
noexcept
{
    return id_transition_change < 0;
}