
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_GTESTEVENTLISTENER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_GTESTEVENTLISTENER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    class GTestEventListener final : public testing::EmptyTestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        GTestEventListener();
        GTestEventListener(const GTestEventListener &)             = delete;
        GTestEventListener(GTestEventListener &&)                  = delete;
        GTestEventListener & operator=(const GTestEventListener &) = delete;
        GTestEventListener & operator=(GTestEventListener &&)      = delete;
        virtual ~GTestEventListener();

        //         void OnEnvironmentsSetUpStart(const testing::UnitTest & unit_test) override;
        //         void OnEnvironmentsSetUpEnd(const testing::UnitTest & unit_test) override;
        //         void OnTestSuiteStart(const testing::TestSuite & test_suite) override;
        //         void OnTestSuiteEnd(const testing::TestSuite & test_suite) override;
        // #ifndef GTEST_REMOVE_LEGACY_TEST_CASEAPI_
        //         void OnTestCaseStart(const testing::TestCase &) override;
        //         void OnTestCaseEnd(const testing::TestCase &) override;
        // #endif
        //         void OnTestProgramStart(const testing::UnitTest & unit_test) override;
        //         void OnTestProgramEnd(const testing::UnitTest & unit_test) override;
        //         void OnTestStart(const testing::TestInfo & test_info) override;
        //         void OnTestEnd(const testing::TestInfo & test_info) override;
        //         void OnTestIterationStart(const testing::UnitTest & unit_test, int /*iteration*/) override;
        //         void OnTestIterationEnd(const testing::UnitTest & unit_test, int iteration) override;
        //         void OnEnvironmentsTearDownStart(const testing::UnitTest & unit_test) override;
        //         void OnEnvironmentsTearDownEnd(const testing::UnitTest & unit_test) override;
        //         void OnTestPartResult(const testing::TestPartResult & test_part_result) override;
        //         void OnTestDisabled(testing::TestInfo const& test_info) override;

        //     protected:
    private:

        std::string m_currentTestCaseName;
        std::string m_currentTestName;
        std::string m_currentTestSuiteName;
    };
}
#endif
