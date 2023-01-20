
#include <rules/sdlc/common/app/ApplicationTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr ApplicationTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.ApplicationTest"));

ApplicationTest::ApplicationTest()
// : m_targetUnderTest()
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

    // m_targetUnderTest = new Base64Helper();
}

void ApplicationTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // delete m_targetUnderTest;
}

TEST_F(ApplicationTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
