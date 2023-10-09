
#include <com/github/doevelopper/rules/sdlc/timers/Timer.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;

log4cxx::LoggerPtr Timer::logger = log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers"));

Timer::Timer()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Timer::~Timer()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
