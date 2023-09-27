
#include <com/github/doevelopper/rules/sdlc/extensions/CustomEnvironment.hpp>

using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr CustomEnvironment::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.CustomEnvironment"));

CustomEnvironment::CustomEnvironment()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

CustomEnvironment::~CustomEnvironment()
{
    // FIXME: No appender could be found for logger
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void CustomEnvironment::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    setenv("TERM", "xterm-256color", 0);
}

void CustomEnvironment::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
