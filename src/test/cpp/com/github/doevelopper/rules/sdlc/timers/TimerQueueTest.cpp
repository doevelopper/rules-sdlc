
#include <com/github/doevelopper/rules/sdlc/timers/TimerQueueTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;
using namespace com::github::doevelopper::rules::sdlc::timers::test;

log4cxx::LoggerPtr TimerQueueTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.test.TimerQueueTest"));

TimerQueueTest::TimerQueueTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerQueueTest::~TimerQueueTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TimerQueueTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new TimerQueue();
}

void TimerQueueTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(TimerQueueTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
