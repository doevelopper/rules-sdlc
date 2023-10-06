
#include <com/github/doevelopper/rules/sdlc/app/TimeoutGuard.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr TimeoutGuard::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.TimeoutGuard"));

TimeoutGuard::TimeoutGuard()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeoutGuard::~TimeoutGuard()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
