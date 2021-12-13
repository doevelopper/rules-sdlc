
#include <rules/sdlc/std/ConfigurableEventListener.hpp>

using namespace rules::sdlc::stdc;
using namespace rules::sdlc::stdc::test;

log4cxx::LoggerPtr ConfigurableEventListener::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdtest.ConfigurableEventListener"));
log4cxx::LoggerPtr ConfigurableEventListener::Builder::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdtest.ConfigurableEventListener.Builder"));

ConfigurableEventListener::Builder::~Builder()
{
     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ConfigurableEventListener::Builder::Builder(testing::TestEventListener* eventListener)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_eventListener = eventListener;
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showProgramStartEnd()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_programStartEnd = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showIterationsStartEnd()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_iterationsStartEnd = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showTestCases()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_testCases = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showTestNames()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_testNames = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showSuccesses()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_successes = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showFailures()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_failures = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showInlineFailures()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_inlineFailures = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showEnvironment()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_environment = true;
    return (*this);
}

ConfigurableEventListener::Builder ConfigurableEventListener::Builder::showSkips()
{
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    this->m_skip = true;
    return (*this);
}

ConfigurableEventListener* ConfigurableEventListener::Builder::build()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    return (
        new ConfigurableEventListener(
            this->m_eventListener,
            this->m_programStartEnd,
            this->m_iterationsStartEnd,
            this->m_testCases,
            this->m_testNames,
            this->m_successes,
            this->m_failures,
            this->m_inlineFailures,
            this->m_environment,
            this->m_skip
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
                                const bool showEnvironment,
                                const bool showSkips)
    :  m_eventListener(eventListener)
    ,  m_showProgramStartEnd(showProgramStartEnd)
    ,  m_showIterationsStartEnd(showIterationsStartEnd)
    ,  m_showTestCases(showTestCases)
    ,  m_showTestNames(showTestNames)
    ,  m_showSuccesses(showSuccesses)
    ,  m_showFailures(showFailures)
    ,  m_showInlineFailures(showInlineFailures)
    ,  m_showEnvironment(showEnvironment)
    ,  m_showSkips(showSkips)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ConfigurableEventListener::~ConfigurableEventListener()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    delete m_eventListener;
}

void ConfigurableEventListener::OnTestProgramStart(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showProgramStartEnd)
    {
        this->m_eventListener->OnTestProgramStart(unit_test);
    }
}

void ConfigurableEventListener::OnTestIterationStart(const testing::UnitTest& unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showIterationsStartEnd)
    {
        this->m_eventListener->OnTestIterationStart(unit_test, iteration);
    }
}

void ConfigurableEventListener::OnEnvironmentsSetUpStart(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showEnvironment)
    {
        this->m_eventListener->OnEnvironmentsSetUpStart(unit_test);
    }
}

void ConfigurableEventListener::OnEnvironmentsSetUpEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showEnvironment)
    {
        this->m_eventListener->OnEnvironmentsSetUpEnd(unit_test);
    }
}

void ConfigurableEventListener::OnTestCaseStart(const testing::TestCase& test_case)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showTestCases)
    {
        this->m_eventListener->OnTestCaseStart(test_case);
    }
}

void ConfigurableEventListener::OnTestStart(const testing::TestInfo& test_info)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showTestNames)
    {
        this->m_eventListener->OnTestStart(test_info);
    }
}

void ConfigurableEventListener::OnTestPartResult(const testing::TestPartResult& result)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    if (this->m_showSuccesses && result.passed())
    {
        this->m_eventListener->OnTestPartResult(result);
    }

    if (this->m_showFailures && result.failed())
    {
        this->m_eventListener->OnTestPartResult(result);
    }
}

void ConfigurableEventListener::OnTestEnd(const testing::TestInfo& test_info)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
/*
            if ((this->m_showInlineFailures && test_info.result()->Failed())
                    || (this->m_showSuccesses && !test_info.result()->Failed())) {
                this->m_eventListener->OnTestEnd(test_info);
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

    if((m_showInlineFailures && test_info.result()->Failed())
       || (m_showSuccesses && test_info.result()->Passed())
       || (m_showSkips && test_info.result()->Skipped()))
    {
        m_eventListener->OnTestEnd(test_info);
    }
}

void ConfigurableEventListener::OnTestCaseEnd(const testing::TestCase& test_case)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showTestCases)
    {
        this->m_eventListener->OnTestCaseEnd(test_case);
    }
}

void ConfigurableEventListener::OnEnvironmentsTearDownStart(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showEnvironment)
    {
        this->m_eventListener->OnEnvironmentsTearDownStart(unit_test);
    }
}

void ConfigurableEventListener::OnEnvironmentsTearDownEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showEnvironment)
    {
        this->m_eventListener->OnEnvironmentsTearDownEnd(unit_test);
    }
}

void ConfigurableEventListener::OnTestIterationEnd(const testing::UnitTest& unit_test, int iteration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showIterationsStartEnd)
    {
        this->m_eventListener->OnTestIterationEnd(unit_test, iteration);
    }
}

void ConfigurableEventListener::OnTestProgramEnd(const testing::UnitTest& unit_test)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if (this->m_showProgramStartEnd)
    {
        this->m_eventListener->OnTestProgramEnd(unit_test);
    }
}
