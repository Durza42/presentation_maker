#include <SDL2/SDL.h>

#include "Context.h"
#include "Diapo.h"
#include "Events.h"

/**
 * @brief main class; manage window refresh, events, etc.
 */
class Game : public Context
{
   public:

    Game();

    void init();
    void main_loop();
    bool manage_events();
    void update_screen();

   private:

    /// @brief the diaporama to be shown
    Diapo m_diapo;

    /// @brief the class interfacing event managing
    Events m_events;
};