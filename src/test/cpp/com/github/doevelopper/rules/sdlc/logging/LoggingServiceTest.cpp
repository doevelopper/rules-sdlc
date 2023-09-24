#include <com/github/doevelopper/rules/sdlc/logging/LoggingServiceTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::logging::test;

// log4cxx::LoggerPtr LoggingServiceTest::logger =
//     log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.logging.test.LoggingServiceTest"));

LoggingServiceTest::LoggingServiceTest()
// : m_targetUnderTest()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

LoggingServiceTest::~LoggingServiceTest()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void LoggingServiceTest::SetUp()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // m_targetUnderTest = new OptionDescription();
}

void LoggingServiceTest::TearDown()
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TEST_F(LoggingServiceTest, test_Simple)
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
