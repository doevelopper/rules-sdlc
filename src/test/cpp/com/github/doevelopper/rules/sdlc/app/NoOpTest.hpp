
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_NOOPTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_NOOPTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class NoOpTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        NoOpTest();
        NoOpTest(const NoOpTest &)             = delete;
        NoOpTest(NoOpTest &&)                  = delete;
        NoOpTest & operator=(const NoOpTest &) = delete;
        NoOpTest & operator=(NoOpTest &&)      = delete;
        virtual ~NoOpTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::NoOp * m_targetUnderTest;

    private:
    };
}
#endif
