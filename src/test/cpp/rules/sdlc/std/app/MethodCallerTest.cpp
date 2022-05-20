
#include <rules/sdlc/std/app/MethodCallerTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr MethodCallerTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.MethodCallerTest"));

MethodCallerTest::MethodCallerTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

MethodCallerTest::~MethodCallerTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void MethodCallerTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    // m_targetUnderTest = new Base64Helper();
}

void MethodCallerTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // delete m_targetUnderTest;
}

TEST_F(MethodCallerTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
