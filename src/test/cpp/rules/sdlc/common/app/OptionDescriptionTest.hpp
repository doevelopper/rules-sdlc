
#ifndef RULES_SDLC_STD_APP_OPTIONDESCRIPTIONTEST_HPP
#define RULES_SDLC_STD_APP_OPTIONDESCRIPTIONTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/common/app/OptionDescription.hpp>

namespace rules::sdlc::stdc::app::test
{

    class OptionDescriptionTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:
        OptionDescriptionTest();
        virtual ~OptionDescriptionTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:
        // rules::sdlc::stdc::app::Application * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(OptionDescriptionTest)
    };
}
#endif
