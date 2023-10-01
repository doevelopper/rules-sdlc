

#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr NoOp::logger = log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.NoOp"));

NoOp::NoOp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

NoOp::~NoOp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
