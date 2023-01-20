
#ifndef RULES_SDLC_STD_APP_APPLICATIONTEST_HPP
#define RULES_SDLC_STD_APP_APPLICATIONTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/common/app/Application.hpp>

namespace rules::sdlc::stdc::app::test
{

    class ApplicationTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:
        ApplicationTest();
        virtual ~ApplicationTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:
        // rules::sdlc::stdc::app::Application * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(ApplicationTest)
    };
}
#endif
