#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERTEST_HPP
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/timers/Timer.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::timers::test
{
    class TimerTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        TimerTest();
        TimerTest(const TimerTest &)             = delete;
        TimerTest(TimerTest &&)                  = delete;
        TimerTest & operator=(const TimerTest &) = delete;
        TimerTest & operator=(TimerTest &&)      = delete;
        virtual ~TimerTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:

        com::github::doevelopper::rules::sdlc::timers::Timer * m_targetUnderTest;
    };
}
#endif
