
#include <com/github/doevelopper/rules/sdlc/extensions/TestDriver.hpp>

using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr TestDriver::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.TestDriver"));

TestDriver::TestDriver()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TestDriver::~TestDriver()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
