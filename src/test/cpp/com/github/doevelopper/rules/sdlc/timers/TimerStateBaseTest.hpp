#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATEBASETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TIMERSTATEBASETEST_HPP
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/timers/TimerStateBase.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::timers::test
{
    class TimerStateBaseTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        TimerStateBaseTest();
        TimerStateBaseTest(const TimerStateBaseTest &)             = delete;
        TimerStateBaseTest(TimerStateBaseTest &&)                  = delete;
        TimerStateBaseTest & operator=(const TimerStateBaseTest &) = delete;
        TimerStateBaseTest & operator=(TimerStateBaseTest &&)      = delete;
        virtual ~TimerStateBaseTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:

        com::github::doevelopper::rules::sdlc::timers::TimerStateBase * m_targetUnderTest;
    };
}
#endif
