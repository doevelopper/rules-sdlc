
#include <com/github/doevelopper/rules/sdlc/app/PluginInterfaceTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

using ::testing::Return;

log4cxx::LoggerPtr PluginInterfaceTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.PluginInterfaceTest"));

PluginInterfaceTest::PluginInterfaceTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PluginInterfaceTest::~PluginInterfaceTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void PluginInterfaceTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_targetUnderTest = new PluginInterfaceMock();

    // ON_CALL(m_targetUnderTest, shutdown())
    //     .WillByDefault();
}

void PluginInterfaceTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(PluginInterfaceTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
