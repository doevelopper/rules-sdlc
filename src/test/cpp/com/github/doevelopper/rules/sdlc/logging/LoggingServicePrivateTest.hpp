#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICEPRIVATETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICEPRIVATETEST_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingServicePrivate.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::logging::test
{
    class LoggingServicePrivateTest : public ::testing::Test
    {
        // LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        LoggingServicePrivateTest();
        LoggingServicePrivateTest(const LoggingServicePrivateTest &)             = delete;
        LoggingServicePrivateTest(LoggingServicePrivateTest &&)                  = delete;
        LoggingServicePrivateTest & operator=(const LoggingServicePrivateTest &) = delete;
        LoggingServicePrivateTest & operator=(LoggingServicePrivateTest &&)      = delete;
        virtual ~LoggingServicePrivateTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        // com::github::doevelopper::rules::sdlc::logging::LoggingServicePrivate * m_targetUnderTest;

    private:
    };
}
#endif
