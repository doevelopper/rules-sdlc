#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERQUEUE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERQUEUE_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::timers
{
    class TimerQueue
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        TimerQueue() noexcept;
        TimerQueue(const TimerQueue &) noexcept             = default;
        TimerQueue(TimerQueue &&) noexcept                  = default;
        TimerQueue & operator=(const TimerQueue &) noexcept = default;
        TimerQueue & operator=(TimerQueue &&) noexcept      = default;
        virtual ~TimerQueue() noexcept;

    protected:
    private:
    };
}

#endif
