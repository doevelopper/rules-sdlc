
#include <com/github/doevelopper/rules/sdlc/timers/TimerStateTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;
using namespace com::github::doevelopper::rules::sdlc::timers::test;

log4cxx::LoggerPtr TimerStateTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.test.TimerStateTest"));

TimerStateTest::TimerStateTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerStateTest::~TimerStateTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TimerStateTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new TimerState();
}

void TimerStateTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(TimerStateTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
