
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTORTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTORTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/Executor.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class ExecutorTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        ExecutorTest();
        ExecutorTest(const ExecutorTest &)             = delete;
        ExecutorTest(ExecutorTest &&)                  = delete;
        ExecutorTest & operator=(const ExecutorTest &) = delete;
        ExecutorTest & operator=(ExecutorTest &&)      = delete;
        virtual ~ExecutorTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::Executor * m_targetUnderTest;

    private:
    };
}
#endif
