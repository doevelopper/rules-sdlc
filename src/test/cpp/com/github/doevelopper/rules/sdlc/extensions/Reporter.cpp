
#include <com/github/doevelopper/rules/sdlc/extensions/Reporter.hpp>

using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr Reporter::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.Reporter"));

Reporter::Reporter()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Reporter::~Reporter()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
