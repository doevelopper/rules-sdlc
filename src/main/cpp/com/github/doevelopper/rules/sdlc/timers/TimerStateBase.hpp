#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATEBASE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATEBASE_HPP

#include <atomic>
#include <chrono>
#include <memory>

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::timers
{
    class TimerStateBase : public std::enable_shared_from_this<TimerStateBase>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        using clock_type   = std::chrono::high_resolution_clock;
        using time_point   = std::chrono::time_point<clock_type>;
        using milliseconds = std::chrono::milliseconds;

        TimerStateBase() noexcept;
        TimerStateBase(const TimerStateBase &) noexcept             = default;
        TimerStateBase(TimerStateBase &&) noexcept                  = default;
        TimerStateBase & operator=(const TimerStateBase &) noexcept = default;
        TimerStateBase & operator=(TimerStateBase &&) noexcept      = default;
        virtual ~TimerStateBase() noexcept;

    protected:
    private:
    };
}

#endif
