
#include <com/github/doevelopper/rules/sdlc/timers/TimerStateBaseTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;
using namespace com::github::doevelopper::rules::sdlc::timers::test;

log4cxx::LoggerPtr TimerStateBaseTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.test.TimerStateBaseTest"));

TimerStateBaseTest::TimerStateBaseTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerStateBaseTest::~TimerStateBaseTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TimerStateBaseTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new TimerStateBase();
}

void TimerStateBaseTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(TimerStateBaseTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
