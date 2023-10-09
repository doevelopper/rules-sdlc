
#include <com/github/doevelopper/rules/sdlc/timers/TimerQueue.hpp>

using namespace com::github::doevelopper::rules::sdlc::timers;

log4cxx::LoggerPtr TimerQueue::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.timers.TimerQueue"));

TimerQueue::TimerQueue()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimerQueue::~TimerQueue()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
