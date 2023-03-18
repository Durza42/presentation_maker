#include "Events.h"

/**
 * @brief Construct a new Events:: Events object
 */
Events::Events():
        m_keys { {false} },
        m_request_close { false }
{

}


/**
 * @brief reads new events and updates the differents attributes of the class
 * 
 * @return true if any event occured; 
 * @return false otherwise.
 */
bool Events::update() noexcept
{
    if (SDL_PollEvent (&m_event))
    {
        do
        {
            switch (m_event.type)
            {
                case SDL_QUIT:
                    m_request_close = true;
               break;
                case SDL_KEYDOWN:
                    m_keys[m_event.key.keysym.scancode] = true;
               break;
                case SDL_KEYUP:
                    m_keys[m_event.key.keysym.scancode] = false;
               break;
            }
        } while (SDL_PollEvent (&m_event));

        return true;
    }
    else
    {
        return false;
    }
}
