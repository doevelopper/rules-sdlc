#ifndef CFS_COM_CONFIGURABLEEVENTLISTENER_HPP
#define CFS_COM_CONFIGURABLEEVENTLISTENER_HPP

#include <iostream>
#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <cfs/com/LoggingService.hpp>

namespace cfs::com::test
{

class ConfigurableEventListener : public testing::TestEventListener
{
	LOG4CXX_DECLARE_STATIC_LOGGER
 public:
    class Builder
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        testing::TestEventListener* eventListener;

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
        ConfigurableEventListener* build();
    protected:

    private:
        bool programStartEnd = false;
        bool iterationsStartEnd = false;
        bool testCases = false;
        bool testNames = false;
        bool successes = false;
        bool failures = false;
        bool inlineFailures = false;
        bool environment = false;
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
                              const bool showEnvironment);

    testing::TestEventListener * eventListener;
    const bool showProgramStartEnd = false;
    const bool showIterationsStartEnd = false;
    const bool showTestCases = false;
    const bool showTestNames = false;
    const bool showSuccesses = false;
    const bool showFailures = false;
    const bool showInlineFailures = false;
    const bool showEnvironment = false;
};

}

#endif

