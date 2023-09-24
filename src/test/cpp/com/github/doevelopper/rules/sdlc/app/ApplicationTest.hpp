
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_APPLICATIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_APPLICATIONTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/Application.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class ApplicationTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        ApplicationTest();
        ApplicationTest(const ApplicationTest &)             = delete;
        ApplicationTest(ApplicationTest &&)                  = delete;
        ApplicationTest & operator=(const ApplicationTest &) = delete;
        ApplicationTest & operator=(ApplicationTest &&)      = delete;
        virtual ~ApplicationTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::Application * m_targetUnderTest;

    private:
    };
}
#endif
