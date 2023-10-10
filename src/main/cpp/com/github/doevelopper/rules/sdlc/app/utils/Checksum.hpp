
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_CHECKSUM_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_CHECKSUM_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

#include <string>
#include <string_view>
#include <vector>

namespace com::github::doevelopper::rules::sdlc::app::utils
{
    class Checksum
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Checksum();
        virtual ~Checksum();

        std::string toHex(std::vector<std::uint8_t> const & digest);
        std::vector<std::uint8_t> sha256sum(void const * data, size_t len);
        std::vector<std::uint8_t> sha256sum(std::string_view data);
        std::vector<std::uint8_t> sha256sum(std::vector<std::uint8_t> const & data);

        std::vector<std::uint8_t> md5sum(void const * data, size_t len);
        std::vector<std::uint8_t> md5sum(std::string_view data);
        std::vector<std::uint8_t> md5sum(std::vector<std::uint8_t> const & data);

    protected:
    private:

        Q_DEFAULT_COPY_MOVE(Checksum)
    };
}
#endif
