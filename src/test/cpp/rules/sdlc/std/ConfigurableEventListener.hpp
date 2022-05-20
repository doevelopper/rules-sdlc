#ifndef SDLC_COM_CONFIGURABLEEVENTLISTENER_HPP
#define SDLC_COM_CONFIGURABLEEVENTLISTENER_HPP

#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::test
{

    class ConfigurableEventListener : public testing::TestEventListener
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        class Builder
        {
            LOG4CXX_DECLARE_STATIC_LOGGER
            testing::TestEventListener* m_eventListener;

        public:
            Builder() = delete;
            Builder(const Builder&) = default;
            Builder(Builder&&) = delete;
            Builder& operator=(const Builder&) = delete;
            Builder& operator=(Builder&&) = delete;
            virtual ~Builder();

            Builder(testing::TestEventListener* eventListener);

            Builder showProgramStartEnd();
            Builder showIterationsStartEnd();
            Builder showTestCases();
            Builder showTestNames();
            Builder showSuccesses();
            Builder showFailures();
            Builder showInlineFailures();
            Builder showEnvironment();
            Builder showSkips();
            ConfigurableEventListener* build();
        protected:

        private:
            bool m_programStartEnd = false;
            bool m_iterationsStartEnd = false;
            bool m_testCases = false;
            bool m_testNames = false;
            bool m_successes = false;
            bool m_failures = false;
            bool m_inlineFailures = false;
            bool m_environment = false;
            bool m_skip = false;
        };

        ConfigurableEventListener() = delete;
        ConfigurableEventListener(const ConfigurableEventListener&) = delete;
        ConfigurableEventListener(ConfigurableEventListener&&) = delete;
        ConfigurableEventListener& operator=(const ConfigurableEventListener&) = delete;
        ConfigurableEventListener& operator=(ConfigurableEventListener&&) = delete;
        virtual ~ConfigurableEventListener() override ; //If the base destructor is not virtual then the compile crashes

        virtual void OnTestProgramStart(const testing::UnitTest& unit_test) override;
        virtual void OnTestIterationStart(const testing::UnitTest& unit_test, int iteration) override;
        virtual void OnEnvironmentsSetUpStart(const testing::UnitTest& unit_test) override;
        virtual void OnEnvironmentsSetUpEnd(const testing::UnitTest& unit_test) override;
        virtual void OnTestCaseStart(const testing::TestCase& test_case) override;
        virtual void OnTestStart(const testing::TestInfo& test_info) override;
        virtual void OnTestPartResult(const testing::TestPartResult& result) override;
        virtual void OnTestEnd(const testing::TestInfo& test_info) override;
        virtual void OnTestCaseEnd(const testing::TestCase& test_case) override;
        virtual void OnEnvironmentsTearDownStart(const testing::UnitTest& unit_test) override;
        virtual void OnEnvironmentsTearDownEnd(const testing::UnitTest& unit_test) override;
        virtual void OnTestIterationEnd(const testing::UnitTest& unit_test, int iteration) override;
        virtual void OnTestProgramEnd(const testing::UnitTest& unit_test) override;

    protected:

    private:

        ConfigurableEventListener(testing::TestEventListener * eventListener,
                                const bool showProgramStartEnd,
                                const bool showIterationsStartEnd,
                                const bool showTestCases,
                                const bool showTestNames,
                                const bool showSuccesses,
                                const bool showFailures,
                                const bool showInlineFailures,
                                const bool showEnvironment,
                                const bool showSkips);

        testing::TestEventListener * m_eventListener;
        const bool m_showProgramStartEnd = false;
        const bool m_showIterationsStartEnd = false;
        const bool m_showTestCases = false;
        const bool m_showTestNames = false;
        const bool m_showSuccesses = false;
        const bool m_showFailures = false;
        const bool m_showInlineFailures = false;
        const bool m_showEnvironment = false;
        const bool m_showSkips = false;
    };
}

#endif
