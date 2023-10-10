
#include <com/github/doevelopper/rules/sdlc/app/TimeoutGuardTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

log4cxx::LoggerPtr TimeoutGuardTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.TimeoutGuardTest"));

TimeoutGuardTest::TimeoutGuardTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeoutGuardTest::~TimeoutGuardTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TimeoutGuardTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_targetUnderTest =
        new TimeoutGuard(std::chrono::milliseconds {5}, std::bind(&TimeoutGuardTest::shouldTrigger, this));
}

void TimeoutGuardTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

void TimeoutGuardTest::shouldTrigger()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TEST_F(TimeoutGuardTest, Test_TimeoutGuardExpiration)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->triggered.store(false);
    this->m_targetUnderTest->watch();
    std::this_thread::sleep_for(std::chrono::milliseconds {10});
    EXPECT_FALSE(this->triggered.load());

    this->triggered.store(false);
    this->m_targetUnderTest->watch();
    std::this_thread::sleep_for(std::chrono::milliseconds {10});
    EXPECT_FALSE(this->triggered.load());
}

TEST_F(TimeoutGuardTest, Test_TimeoutGuardNoAlarm)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    this->triggered.store(false);
    this->m_targetUnderTest->watch();
    std::this_thread::sleep_for(std::chrono::milliseconds {1});
    EXPECT_FALSE(this->triggered.load());

    this->triggered.store(false);
    this->m_targetUnderTest->watch();

    for (auto i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds {1});
        this->m_targetUnderTest->touch();
    }

    EXPECT_FALSE(this->triggered.load());
}
