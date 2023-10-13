
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandler.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr QueuedHandler::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.QueuedHandler"));

QueuedHandler::QueuedHandler() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QueuedHandler::~QueuedHandler() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
