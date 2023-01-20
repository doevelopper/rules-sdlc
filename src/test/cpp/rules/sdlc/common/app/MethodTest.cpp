
#include <rules/sdlc/common/app/MethodTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr MethodTest::logger = log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.MethodTest"));

MethodTest::MethodTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

MethodTest::~MethodTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void MethodTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Base64Helper();
}

void MethodTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // delete m_targetUnderTest;
}

TEST_F(MethodTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
