
#ifndef RULES_SDLC_STD_APP_EXECUTIONCONTEXTTEST_HPP
#define RULES_SDLC_STD_APP_EXECUTIONCONTEXTTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/std/app/ExecutionContext.hpp>

namespace rules::sdlc::stdc::app::test
{

    class ExecutionContextTest : public ::testing::Test
    {
    LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:

        ExecutionContextTest();
        virtual ~ExecutionContextTest();

        void SetUp() override;
        void TearDown() override;

    protected:

    private:

        // rules::sdlc::stdc::app::Application * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(ExecutionContextTest)
    };
}
#endif
