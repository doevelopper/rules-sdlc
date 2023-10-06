
#include <com/github/doevelopper/rules/sdlc/app/ApplicationTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

log4cxx::LoggerPtr ApplicationTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.ApplicationTest"));

ApplicationTest::ApplicationTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ApplicationTest::~ApplicationTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ApplicationTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_targetUnderTest = new Application();
}

void ApplicationTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(ApplicationTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
