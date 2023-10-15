
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandlerMock.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

log4cxx::LoggerPtr QueuedHandlerMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.QueuedHandlerMock"));

QueuedHandlerMock::QueuedHandlerMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

QueuedHandlerMock::~QueuedHandlerMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
