#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TimerQueueTest_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_TIMERS_TimerQueueTest_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/timers/TimerQueue.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::timers::test
{
    class TimerQueueTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        TimerQueueTest();
        TimerQueueTest(const TimerQueueTest &)             = delete;
        TimerQueueTest(TimerQueueTest &&)                  = delete;
        TimerQueueTest & operator=(const TimerQueueTest &) = delete;
        TimerQueueTest & operator=(TimerQueueTest &&)      = delete;
        virtual ~TimerQueueTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:

        com::github::doevelopper::rules::sdlc::timers::TimerQueue * m_targetUnderTest;
    };
}
#endif
