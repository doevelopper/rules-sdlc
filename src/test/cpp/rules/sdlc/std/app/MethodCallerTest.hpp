
#ifndef RULES_SDLC_STD_APP_METHODCALLERTEST_HPP
#define RULES_SDLC_STD_APP_METHODCALLERTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/std/app/MethodCaller.hpp>

namespace rules::sdlc::stdc::app::test
{

    class MethodCallerTest : public ::testing::Test
    {
    LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:

        MethodCallerTest();
        virtual ~MethodCallerTest();

        void SetUp() override;
        void TearDown() override;

    protected:

    private:

        // rules::sdlc::stdc::app::Application * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(MethodCallerTest)
    };
}
#endif
