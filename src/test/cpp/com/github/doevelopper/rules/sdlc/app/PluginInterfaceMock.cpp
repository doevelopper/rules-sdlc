
#include <com/github/doevelopper/rules/sdlc/app/PluginInterfaceMock.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::test;

log4cxx::LoggerPtr PluginInterfaceMock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.PluginInterfaceMock"));

PluginInterfaceMock::PluginInterfaceMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PluginInterfaceMock::~PluginInterfaceMock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
