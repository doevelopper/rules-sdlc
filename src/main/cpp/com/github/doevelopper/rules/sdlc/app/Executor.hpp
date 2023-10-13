
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTOR_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTOR_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <boost/asio.hpp>

#include <queue>

namespace com::github::doevelopper::rules::sdlc::app
{
    class Executor
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Executor() noexcept;
        Executor(const Executor &) noexcept             = default;
        Executor(Executor &&) noexcept                  = default;
        Executor & operator=(const Executor &) noexcept = default;
        Executor & operator=(Executor &&) noexcept      = default;
        virtual ~Executor() noexcept;

    protected:
    private:
    };
}
#endif
