#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::timers
{
    class Timer
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Timer() noexcept;
        Timer(const Timer &) noexcept             = default;
        Timer(Timer &&) noexcept                  = default;
        Timer & operator=(const Timer &) noexcept = default;
        Timer & operator=(Timer &&) noexcept      = default;
        virtual ~Timer() noexcept;

    protected:
    private:
    };
}

#endif
