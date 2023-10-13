
#include <com/github/doevelopper/rules/sdlc/app/Executor.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr Executor::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.Executor"));

Executor::Executor() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Executor::~Executor() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
