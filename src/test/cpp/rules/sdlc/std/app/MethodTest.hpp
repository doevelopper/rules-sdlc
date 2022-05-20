
#ifndef RULES_SDLC_STD_APP_METHODTEST_HPP
#define RULES_SDLC_STD_APP_METHODTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/std/app/Method.hpp>

namespace rules::sdlc::stdc::app::test
{

    class MethodTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:

        MethodTest();
        virtual ~MethodTest();

        void SetUp() override;
        void TearDown() override;

    protected:

    private:

        // rules::sdlc::stdc::app::Application * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(MethodTest)
    };
}
#endif
