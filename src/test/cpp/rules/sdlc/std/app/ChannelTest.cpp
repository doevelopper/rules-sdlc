
#include <rules/sdlc/std/app/ChannelTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr ChannelTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.ChannelTest"));

ChannelTest::ChannelTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

ChannelTest::~ChannelTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void ChannelTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );

    // m_targetUnderTest = new Base64Helper();
}

void ChannelTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // delete m_targetUnderTest;
}

TEST_F(ChannelTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
