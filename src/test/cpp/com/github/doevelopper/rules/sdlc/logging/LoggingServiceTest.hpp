
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICETEST_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::logging::test
{
    class LoggingServiceTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        LoggingServiceTest();
        LoggingServiceTest(const LoggingServiceTest &)             = delete;
        LoggingServiceTest(LoggingServiceTest &&)                  = delete;
        LoggingServiceTest & operator=(const LoggingServiceTest &) = delete;
        LoggingServiceTest & operator=(LoggingServiceTest &&)      = delete;
        virtual ~LoggingServiceTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        // com::github::doevelopper::rules::sdlc::logging::LoggingService * m_targetUnderTest;

    private:
    };
}

#endif
