
#include <rules/sdlc/common/app/ExecutionContextTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr ExecutionContextTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.ExecutionContextTest"));

ExecutionContextTest::ExecutionContextTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ExecutionContextTest::~ExecutionContextTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ExecutionContextTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Base64Helper();
}

void ExecutionContextTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // delete m_targetUnderTest;
}

TEST_F(ExecutionContextTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
