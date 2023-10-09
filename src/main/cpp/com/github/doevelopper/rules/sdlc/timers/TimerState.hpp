#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATE_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::timers
{
    class TimerState
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        TimerState() noexcept;
        TimerState(const TimerState &) noexcept             = default;
        TimerState(TimerState &&) noexcept                  = default;
        TimerState & operator=(const TimerState &) noexcept = default;
        TimerState & operator=(TimerState &&) noexcept      = default;
        virtual ~TimerState() noexcept;

    protected:
    private:
    };
}

#endif
