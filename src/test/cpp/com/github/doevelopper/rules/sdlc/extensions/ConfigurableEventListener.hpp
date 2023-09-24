
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_CONFIGURABLEEVENTLISTENER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_CONFIGURABLEEVENTLISTENER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    class ConfigurableEventListener : public testing::TestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        class Builder
        {
            LOG4CXX_DECLARE_STATIC_LOGGER
            testing::TestEventListener * m_eventListener;

        public:

            Builder()                            = delete;
            Builder(const Builder &)             = default;
            Builder(Builder &&)                  = delete;
            Builder & operator=(const Builder &) = delete;
            Builder & operator=(Builder &&)      = delete;
            virtual ~Builder();

            Builder(testing::TestEventListener * eventListener);

            Builder showProgramStartEnd();
            Builder showIterationsStartEnd();
            Builder showTestCases();
            Builder showTestNames();
            Builder showSuccesses();
            Builder showFailures();
            Builder showInlineFailures();
            Builder showEnvironment();
            Builder showSkips();
            Builder showTestSuite();
            ConfigurableEventListener * build();

        protected:
        private:

            bool m_programStartEnd    = false;
            bool m_iterationsStartEnd = false;
            bool m_testCases          = false;
            bool m_testNames          = false;
            bool m_successes          = false;
            bool m_failures           = false;
            bool m_inlineFailures     = false;
            bool m_environment        = false;
            bool m_skip               = false;
            bool m_TestSuite          = false;
        };

        ConfigurableEventListener();
        ConfigurableEventListener(const ConfigurableEventListener &)             = delete;
        ConfigurableEventListener(ConfigurableEventListener &&)                  = delete;
        ConfigurableEventListener & operator=(const ConfigurableEventListener &) = delete;
        ConfigurableEventListener & operator=(ConfigurableEventListener &&)      = delete;
        virtual ~ConfigurableEventListener(); // If the base destructor is not virtual then the compile crashes

        /*!
        * @brief Before any test activity starts.
        */
        virtual void OnTestProgramStart(const testing::UnitTest & unit_test) override;
        /*!
        * @brief Fired after all test activities have ended.
        */
        virtual void OnTestProgramEnd(const testing::UnitTest & unit_test) override;
        /*!
        * @brief Fired before each iteration of tests starts.iteration is the iteration index, starting from 0.
        */
        virtual void OnTestIterationStart(const testing::UnitTest & unit_test, int iteration) override;
        /*!
        * @brief  Fired after each iteration of tests finishes.
        */
        virtual void OnTestIterationEnd(const testing::UnitTest & unit_test, int iteration) override;
        /*!
        * @brief Fired before environment set-up for each iteration of tests starts.
        */
        virtual void OnEnvironmentsSetUpStart(const testing::UnitTest & unit_test) override;
        /*!
        * @brief ired after environment set-up for each iteration of tests ends.
        */
        virtual void OnEnvironmentsSetUpEnd(const testing::UnitTest & unit_test) override;

        /*!
        * @brief Fired before the test suite starts.
        */
        virtual void OnTestSuiteStart(const testing::TestSuite& test_suite)  override;
        /*!
        * @brief Fired after the test suite ends.
        */
        virtual void OnTestSuiteEnd(const testing::TestSuite& /*test_suite*/)  override;
        //  Legacy API is deprecated but still available
#ifndef GTEST_REMOVE_LEGACY_TEST_CASEAPI_
        virtual void OnTestCaseStart(const testing::TestCase & test_case) override;
        virtual void OnTestCaseEnd(const testing::TestCase & test_case) override;
#endif

        /*!
        * @brief Fired before the test starts.
        */
        virtual void OnTestStart(const testing::TestInfo & test_info) override;
        /*!
        * @brief Fired after the test ends.
        */
        virtual void OnTestEnd(const testing::TestInfo & test_info) override;
        /*!
        * @brief  Fired when a test is disabled.
        */
        virtual void OnTestDisabled(const testing::TestInfo& test_info) override;
        /*!
        * @brief  Fired before environment tear-down for each iteration of tests starts.
        */
        virtual void OnEnvironmentsTearDownStart(const testing::UnitTest & unit_test) override;
        /*!
        * @brief Fired after environment tear-down for each iteration of tests ends.
        */
        virtual void OnEnvironmentsTearDownEnd(const testing::UnitTest & unit_test) override;
        /*!
        * @brief Fired after a failed assertion or a SUCCEED() invocation.
        */
        virtual void OnTestPartResult(const testing::TestPartResult & result) override;

    protected:
    private:

        ConfigurableEventListener(
            testing::TestEventListener * eventListener, const bool showProgramStartEnd,
            const bool showIterationsStartEnd, const bool showTestCases, const bool showTestNames,
            const bool showSuccesses, const bool showFailures, const bool showInlineFailures,
            const bool showEnvironment, const bool showSkips, const bool showTestSuite);

        testing::TestEventListener * m_eventListener;
        const bool m_showProgramStartEnd    = false;
        const bool m_showIterationsStartEnd = false;
        const bool m_showTestCases          = false;
        const bool m_showTestNames          = false;
        const bool m_showSuccesses          = false;
        const bool m_showFailures           = false;
        const bool m_showInlineFailures     = false;
        const bool m_showEnvironment        = false;
        const bool m_showSkips              = false;
        const bool m_showTestSuite          = false;
    };
}
#endif
