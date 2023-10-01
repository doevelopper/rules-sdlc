

#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_Reporter_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_Reporter_HPP

#include <com/github/doevelopper/rules/sdlc/extensions/LifecycleObserver.hpp>

#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    class Reporter : public LifecycleObserver
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Reporter();
        Reporter(const Reporter &)             = delete;
        Reporter(Reporter &&)                  = delete;
        Reporter & operator=(const Reporter &) = delete;
        Reporter & operator=(Reporter &&)      = delete;
        virtual ~Reporter();
        // Reports before any test activity starts.
        void OnProgramStart(const Runner & runner) final;

        // Reports before every test iteration begins.
        void OnIterationStart(const Runner & runner, int iteration) final;

        // Reports before any environment setup is called.
        void OnEnvironmentSetUp(const Runner & runner) final;

        // Reports before every TestCase is set up.
        void OnTestCaseStart(const TestCase & test_case) final;

        // Reports before every test starts.
        void OnTestStart(const TestCase & test_case, const TestInfo & test) final;

        // Reports when an assertion failed on the current running test.
        void OnAssertion(const Assertion & assertion) final;

        // Reports before every test starts.
        void OnTestSkip(const TestCase & test_case, const TestInfo & test) final;

        // Reports before every TestCase is set up.
        void OnTestFailure(const TestCase & test_case, const TestInfo & test) final;

        // Reports before every TestCase is set up.
        void OnTestSuccess(const TestCase & test_case, const TestInfo & test) final;

        // Reports before every TestCase is torn down.
        void OnTestCaseEnd(const TestCase & test_case) final;

        // Reports before any environment setup is called.
        void OnEnvironmentTearDown(const Runner & runner) final;

        // Reports after each test iteration completes.
        void OnIterationEnd(const Runner & runner, int iteration) final;

        // Reports after all test activity is completed.
        void OnProgramEnd(const Runner & runner) final;

    protected:
    private:
    };
}
#endif
