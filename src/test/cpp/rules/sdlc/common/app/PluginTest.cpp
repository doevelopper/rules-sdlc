
#include <rules/sdlc/common/app/PluginTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr PluginTest::logger = log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.PluginTest"));

PluginTest::PluginTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PluginTest::~PluginTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void PluginTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Base64Helper();
}

void PluginTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // delete m_targetUnderTest;
}

TEST_F(PluginTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
