#include <com/github/doevelopper/rules/sdlc/logging/LoggingServicePrivateTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::logging::test;

// log4cxx::LoggerPtr LoggingServicePrivateTest::logger =
//     log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.logging.test.LoggingServicePrivateTest"));

LoggingServicePrivateTest::LoggingServicePrivateTest()
// : m_targetUnderTest()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

LoggingServicePrivateTest::~LoggingServicePrivateTest()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void LoggingServicePrivateTest::SetUp()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // m_targetUnderTest = new OptionDescription();
}

void LoggingServicePrivateTest::TearDown()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TEST_F(LoggingServicePrivateTest, test_Simple)
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
