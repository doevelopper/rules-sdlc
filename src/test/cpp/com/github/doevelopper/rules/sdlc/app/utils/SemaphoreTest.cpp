
#include <com/github/doevelopper/rules/sdlc/app/utils/SemaphoreTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;
using namespace com::github::doevelopper::rules::sdlc::app::utils::test;

log4cxx::LoggerPtr SemaphoreTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.SemaphoreTest"));

SemaphoreTest::SemaphoreTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SemaphoreTest::~SemaphoreTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void SemaphoreTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_targetUnderTest = new Semaphore();
}

void SemaphoreTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(SemaphoreTest, Test_Acquire_Release)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_TRUE(this->m_targetUnderTest) << "My condition is not true";
    m_targetUnderTest->acquire();
    // m_targetUnderTest->acquire();
}
