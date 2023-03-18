#include <SDL2/SDL.h>
#include <array>

/**
 * @brief event manager
 * @details This class interfaces the evenments managing.
 * use ::update to update the event queue, and then the constexpr getters to check the state as you wish.
 */
class Events
{
  public:

   Events();

   bool update() noexcept;

   /**
    * @brief getter for Events::m_request_close
    * 
    * @return true if user wants the window to be closed; 
    * @return false otherwise.
    */
   constexpr bool request_close() const noexcept
   {
      return m_request_close;
   }

   /**
    * @brief getter for Events::m_keys_array
    * @details see Events::m_keys_array
    * 
    * @return an array representing the keyboard
    */
   constexpr std::array<bool, SDL_NUM_SCANCODES> get_keys_array() const noexcept
   {
      return m_keys;
   }

   /**
    * @brief return the state of the specified key
    * 
    * @param key the keyboard's key to be checked
    * 
    * @return true if the `key` is pressed; 
    * @return false otherwise.
    */
   constexpr bool key_is_pressed (std::array<bool, SDL_NUM_SCANCODES>::size_type const& key) const noexcept
   {
      return m_keys[key];
   }

  private:

   /// @brief SDL_Event struct, stacking all events
   SDL_Event m_event;

   /// @brief references for every key of the keyboard if it is pressed (true) or not (false)
   std::array<bool, SDL_NUM_SCANCODES> m_keys;

   /// @brief true if the user wants to close the window, false otherwise
   bool m_request_close;
};
