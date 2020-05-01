
#include <cfs/com/ConfigurableEventListener.hpp>

using namespace cfs::com::test;

log4cxx::LoggerPtr ConfigurableEventListener::logger =
    log4cxx::Logger::getLogger(std::string("cfs.com.test.ConfigurableEventListener"));
log4cxx::LoggerPtr ConfigurableEventListener::Builder::logger =
    log4cxx::Logger::getLogger(std::string("cfs.com.test.ConfigurableEventListener.Builder"));

ConfigurableEventListener::Builder::~Builder()
{
     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ConfigurableEventListener::Builder::Builder(testing::TestEventListener* eventListener)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->eventListener = eventListener;
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showProgramStartEnd()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->programStartEnd = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showIterationsStartEnd()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->iterationsStartEnd = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showTestCases()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->testCases = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showTestNames()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->testNames = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showSuccesses()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->successes = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showFailures()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->failures = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showInlineFailures()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->inlineFailures = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showEnvironment()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->environment = true;
    return (*this);
}

ConfigurableEventListener* ConfigurableEventListener::Builder::build()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    return (
        new ConfigurableEventListener(
            this->eventListener,
            this->programStartEnd,
            this->iterationsStartEnd,
            this->testCases,
            this->testNames,
            this->successes,
            this->failures,
            this->inlineFailures,
            this->environment
        )
    );
}


ConfigurableEventListener::ConfigurableEventListener(testing::TestEventListener* eventListener,
                                const bool showProgramStartEnd,
                                const bool showIterationsStartEnd,
                                const bool showTestCases,
                                const bool showTestNames,
                                const bool showSuccesses,
                                const bool showFailures,
                                const bool showInlineFailures,
                                const bool showEnvironment)
  : eventListener(eventListener)
  , showProgramStartEnd(showProgramStartEnd)
  , showIterationsStartEnd(showIterationsStartEnd)
  , showTestCases(showTestCases)
  , showTestNames(showTestNames)
  , showSuccesses(showSuccesses)
  , showFailures(showFailures)
  , showInlineFailures(showInlineFailures)
  , showEnvironment(showEnvironment)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ConfigurableEventListener::~ConfigurableEventListener()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete eventListener;
}

void ConfigurableEventListener::OnTestProgramStart(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showProgramStartEnd) {
                this->eventListener->OnTestProgramStart(unit_test);
            }
}

void ConfigurableEventListener::OnTestIterationStart(const testing::UnitTest& unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showIterationsStartEnd) {
                this->eventListener->OnTestIterationStart(unit_test, iteration);
            }
}

void ConfigurableEventListener::OnEnvironmentsSetUpStart(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showEnvironment) {
                this->eventListener->OnEnvironmentsSetUpStart(unit_test);
            }
}

void ConfigurableEventListener::OnEnvironmentsSetUpEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showEnvironment) {
                this->eventListener->OnEnvironmentsSetUpEnd(unit_test);
            }
}

void ConfigurableEventListener::OnTestCaseStart(const testing::TestCase& test_case)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showTestCases) {
                this->eventListener->OnTestCaseStart(test_case);
            }
}

void ConfigurableEventListener::OnTestStart(const testing::TestInfo& test_info)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showTestNames) {
                this->eventListener->OnTestStart(test_info);
            }
}

void ConfigurableEventListener::OnTestPartResult(const testing::TestPartResult& result)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showSuccesses && result.passed()) {
                this->eventListener->OnTestPartResult(result);
            }

            if (this->showFailures && result.failed()) {
                this->eventListener->OnTestPartResult(result);
            }
}

void ConfigurableEventListener::OnTestEnd(const testing::TestInfo& test_info)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
/*
            if ((this->showInlineFailures && test_info.result()->Failed())
                    || (this->showSuccesses && !test_info.result()->Failed())) {
                this->eventListener->OnTestEnd(test_info);
            }
*/
/*
    if((showInlineFailures && test_info.result()->Failed())
        || (showSuccesses && test_info.result()->Passed())
        || (showSkips && test_info.result()->Skipped()))
    {
        eventListener->OnTestEnd(test_info);
    }
*/
}

void ConfigurableEventListener::OnTestCaseEnd(const testing::TestCase& test_case)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showTestCases) {
                this->eventListener->OnTestCaseEnd(test_case);
            }
}

void ConfigurableEventListener::OnEnvironmentsTearDownStart(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showEnvironment) {
                this->eventListener->OnEnvironmentsTearDownStart(unit_test);
            }
}

void ConfigurableEventListener::OnEnvironmentsTearDownEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showEnvironment) {
                this->eventListener->OnEnvironmentsTearDownEnd(unit_test);
            }
}

void ConfigurableEventListener::OnTestIterationEnd(const testing::UnitTest& unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showIterationsStartEnd) {
                this->eventListener->OnTestIterationEnd(unit_test, iteration);
            }
}

void ConfigurableEventListener::OnTestProgramEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
            if (this->showProgramStartEnd) {
                this->eventListener->OnTestProgramEnd(unit_test);
            }
}

