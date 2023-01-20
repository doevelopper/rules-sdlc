
#include <rules/sdlc/common/app/OptionDescriptionTest.hpp>

using namespace rules::sdlc::stdc::app;
using namespace rules::sdlc::stdc::app::test;

log4cxx::LoggerPtr OptionDescriptionTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.test.OptionDescriptionTest"));

OptionDescriptionTest::OptionDescriptionTest()
// : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

OptionDescriptionTest::~OptionDescriptionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void OptionDescriptionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Base64Helper();
}

void OptionDescriptionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // delete m_targetUnderTest;
}

TEST_F(OptionDescriptionTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
