
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_TIMEOUTGUARDTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_TIMEOUTGUARDTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/TimeoutGuard.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class TimeoutGuardTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        TimeoutGuardTest();
        TimeoutGuardTest(const TimeoutGuardTest &)             = delete;
        TimeoutGuardTest(TimeoutGuardTest &&)                  = delete;
        TimeoutGuardTest & operator=(const TimeoutGuardTest &) = delete;
        TimeoutGuardTest & operator=(TimeoutGuardTest &&)      = delete;
        virtual ~TimeoutGuardTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        void shouldTrigger();

        com::github::doevelopper::rules::sdlc::app::TimeoutGuard * m_targetUnderTest;
        std::atomic_bool triggered {false};

    private:
    };
}
#endif
