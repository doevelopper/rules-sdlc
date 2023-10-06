
#include <com/github/doevelopper/rules/sdlc/app/utils/SemaphoreLockTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;
using namespace com::github::doevelopper::rules::sdlc::app::utils::test;

log4cxx::LoggerPtr SemaphoreLockTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.SemaphoreLockTest"));

SemaphoreLockTest::SemaphoreLockTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

SemaphoreLockTest::~SemaphoreLockTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void SemaphoreLockTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new SemaphoreLock();
}

void SemaphoreLockTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(SemaphoreLockTest, Test_Acquire)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    Semaphore sem(3);

    std::atomic_int v;
    std::vector<std::jthread> threads;
    for (int i = 0; i < 10; ++i)
    {
        threads.emplace_back([&] {
            SemaphoreLock lock(sem);
            v += 1;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            v -= 1;
        });
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    EXPECT_EQ(v, 3);
    threads.clear();
    EXPECT_EQ(v, 0);
}
