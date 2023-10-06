
#include <com/github/doevelopper/rules/sdlc/app/PluginInterface.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr PluginInterface::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.PluginInterface"));

PluginInterface::PluginInterface()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PluginInterface::~PluginInterface()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
