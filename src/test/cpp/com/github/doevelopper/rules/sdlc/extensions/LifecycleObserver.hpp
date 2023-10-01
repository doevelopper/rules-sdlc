
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_LifecycleObserver_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_LifecycleObserver_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    enum class TestStatus : std::uint8_t
    {
        kRunning,
        kPassed,
        kFailed,
        kSkipped,
    };

    class LifecycleObserver
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        LifecycleObserver();
        LifecycleObserver(const LifecycleObserver &)             = delete;
        LifecycleObserver(LifecycleObserver &&)                  = delete;
        LifecycleObserver & operator=(const LifecycleObserver &) = delete;
        LifecycleObserver & operator=(LifecycleObserver &&)      = delete;
        virtual ~LifecycleObserver();

        /*!
         * @brief Reports before any test is executed.
         */
        virtual void OnProgramStart(const Runner & runner) { }

        /*!
         * @brief Reports before every iteration starts.
         */
        virtual void OnIterationStart(const Runner & runner, int iteration) { }

        /*!
         * @brief Reports before any environment is set up.
         */
        virtual void OnEnvironmentSetUp(const Runner & runner) { }

        /*!
         * @brief  Reports before a TestCase is set up.
         */
        virtual void OnTestCaseStart(const TestCase & test_case) { }

        /*!
         * @brief  Reports before a test starts.
         */
        virtual void OnTestStart(const TestCase & test_case, const TestInfo & test) { }

        /*!
         * @brief Reports when an assertion on the running tests fails.
         */
        virtual void OnAssertion(const Assertion & assertion) { }

        /*!
         * @brief Reports after a test execution was skipped.
         */
        virtual void OnTestSkip(const TestCase & test_case, const TestInfo & test) { }

        /*!
         * @brief Reports after test execution completed with failures.
         */
        virtual void OnTestFailure(const TestCase & test_case, const TestInfo & test) { }

        /*!
         * @brief Reports after test execution completed with no failures.
         */
        virtual void OnTestSuccess(const TestCase & test_case, const TestInfo & test) { }

        /*!
         * @brief Reports before a TestCase is torn down.
         */
        virtual void OnTestCaseEnd(const TestCase & test_case) { }

        /*!
         * @brief Reports before any environment is torn down.
         */
        virtual void OnEnvironmentTearDown(const Runner & runner) { }

        /*!
         * @brief Reports before every iteration starts.
         */
        virtual void OnIterationEnd(const Runner & runner, int iteration) { }

        /*!
         * @brief Reports after all test executed.
         */
        virtual void OnProgramEnd(const Runner & runner) { }

    protected:
    private:
    };
}
#endif
