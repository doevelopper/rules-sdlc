
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandlerTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

log4cxx::LoggerPtr QueuedHandlerTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.QueuedHandlerTest"));

QueuedHandlerTest::QueuedHandlerTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QueuedHandlerTest::~QueuedHandlerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void QueuedHandlerTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_targetUnderTest = new QueuedHandler();
}

void QueuedHandlerTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(QueuedHandlerTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
