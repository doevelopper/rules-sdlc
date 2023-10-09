#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATETEST_HPP
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/timers/TimerState.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::timers::test
{
    class TimerStateTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        TimerStateTest();
        TimerStateTest(const TimerStateTest &)             = delete;
        TimerStateTest(TimerStateTest &&)                  = delete;
        TimerStateTest & operator=(const TimerStateTest &) = delete;
        TimerStateTest & operator=(TimerStateTest &&)      = delete;
        virtual ~TimerStateTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:

        com::github::doevelopper::rules::sdlc::timers::TimerState * m_targetUnderTest;
    };
}
#endif
