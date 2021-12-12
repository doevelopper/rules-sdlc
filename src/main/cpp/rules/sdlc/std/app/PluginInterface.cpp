
#include <rules/sdlc/std/app/PluginInterface.hpp>

using namespace rules::sdlc::stdc::app;

log4cxx::LoggerPtr PluginInterface::logger = log4cxx::Logger::getLogger (
    std::string ( "rules.sdlc.stdc.app.PluginInterface" ) );

PluginInterface::PluginInterface ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }

PluginInterface::~PluginInterface ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }
