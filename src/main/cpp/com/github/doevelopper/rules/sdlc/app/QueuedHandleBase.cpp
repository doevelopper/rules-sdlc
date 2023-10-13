
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandleBase.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr QueuedHandleBase::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.QueuedHandleBase"));

QueuedHandleBase::QueuedHandleBase() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QueuedHandleBase::~QueuedHandleBase() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
