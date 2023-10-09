
#include <com/github/doevelopper/rules/sdlc/timers/TimerTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;
using namespace com::github::doevelopper::rules::sdlc::timers::test;

log4cxx::LoggerPtr TimerTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.test.TimerTest"));

TimerTest::TimerTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerTest::~TimerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TimerTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new Timer();
}

void TimerTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(TimerTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
