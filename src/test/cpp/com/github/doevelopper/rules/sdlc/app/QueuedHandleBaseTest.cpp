
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandleBaseTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

log4cxx::LoggerPtr QueuedHandleBaseTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.QueuedHandleBaseTest"));

QueuedHandleBaseTest::QueuedHandleBaseTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QueuedHandleBaseTest::~QueuedHandleBaseTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void QueuedHandleBaseTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new QueuedHandleBase();
}

void QueuedHandleBaseTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(QueuedHandleBaseTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
