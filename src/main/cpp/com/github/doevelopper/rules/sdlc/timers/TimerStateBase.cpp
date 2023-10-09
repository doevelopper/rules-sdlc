
#include <com/github/doevelopper/rules/sdlc/timers/TimerStateBase.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;

log4cxx::LoggerPtr TimerStateBase::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.TimerStateBase"));

TimerStateBase::TimerStateBase()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerStateBase::~TimerStateBase()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
