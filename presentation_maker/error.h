#include <string>

/**
 * @brief contains error log functions
 */
namespace Error
{
    void log_Critical(std::string const&& app_msg);
    void log_Error(std::string const&& app_msg);
    void log_Warning(std::string const&& app_msg) noexcept;
}
