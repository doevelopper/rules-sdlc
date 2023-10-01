
#include <com/github/doevelopper/rules/sdlc/extensions/LifecycleObserver.hpp>

using namespace com::github::doevelopper::rules::sdlc::extensions::test;

log4cxx::LoggerPtr LifecycleObserver::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.extensions.test.LifecycleObserver"));

LifecycleObserver::LifecycleObserver()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

LifecycleObserver::~LifecycleObserver()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
