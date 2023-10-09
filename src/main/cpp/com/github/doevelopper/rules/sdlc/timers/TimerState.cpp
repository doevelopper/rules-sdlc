
#include <com/github/doevelopper/rules/sdlc/timers/TimerState.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;

log4cxx::LoggerPtr TimerState::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.TimerState"));

TimerState::TimerState()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerState::~TimerState()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
