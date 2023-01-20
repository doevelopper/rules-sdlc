
#ifndef SDLC_COM_GTESTEVENTLISTENER_HPP
#define SDLC_COM_GTESTEVENTLISTENER_HPP
#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <rules/sdlc/common/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::test
{
    class GTestEventListener final : public testing::EmptyTestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        GTestEventListener();
        ~GTestEventListener();
        void OnEnvironmentsSetUpStart(const testing::UnitTest & unit_test) override;
        void OnEnvironmentsSetUpEnd(const testing::UnitTest & unit_test) override;
        void OnTestSuiteStart(const testing::TestSuite & test_suite) override;
        void OnTestSuiteEnd(const testing::TestSuite & test_suite) override;
        void OnTestCaseStart(const testing::TestCase &) override;
        void OnTestCaseEnd(const testing::TestCase &) override;
        void OnTestProgramStart(const testing::UnitTest & unit_test) override;
        void OnTestProgramEnd(const testing::UnitTest & unit_test) override;
        void OnTestStart(const testing::TestInfo & test_info) override;
        void OnTestEnd(const testing::TestInfo & test_info) override;
        void OnTestPartResult(const testing::TestPartResult & test_part_result) override;
        void OnTestIterationStart(const testing::UnitTest & unit_test, int /*iteration*/) override;
        void OnTestIterationEnd(const testing::UnitTest & unit_test, int iteration) override;
        void OnEnvironmentsTearDownStart(const testing::UnitTest & unit_test) override;
        void OnEnvironmentsTearDownEnd(const testing::UnitTest & unit_test) override;

    protected:
    private:
        std::string m_currentTestCaseName;
        std::string m_currentTestName;
    };

}

#endif
