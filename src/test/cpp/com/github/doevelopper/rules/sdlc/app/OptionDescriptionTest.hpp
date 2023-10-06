
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_OPTIONDESCRIPTIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_OPTIONDESCRIPTIONTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/Application.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class OptionDescriptionTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        OptionDescriptionTest();
        OptionDescriptionTest(const OptionDescriptionTest &)             = delete;
        OptionDescriptionTest(OptionDescriptionTest &&)                  = delete;
        OptionDescriptionTest & operator=(const OptionDescriptionTest &) = delete;
        OptionDescriptionTest & operator=(OptionDescriptionTest &&)      = delete;
        virtual ~OptionDescriptionTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::OptionDescription * m_targetUnderTest;

    private:
    };
}
#endif
