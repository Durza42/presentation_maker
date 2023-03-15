#include <SDL2/SDL.h>

#include "Context.h"
#include "Diapo.h"

/**
 * @brief main class; manage window refresh, events, etc.
 */
class Game : public Context
{
   public:

    Game();
    void main_loop();

   private:

    Diapo m_diapo;
};