
#include <project/object/model/NetworkPlugin.hpp>

using namespace rules::sdlc::stdc;

log4cxx::LoggerPtr NetworkPlugin::logger =
    log4cxx::Logger::getLogger(std::string("project.object.model.NetworkPlugin"));

NetworkPlugin::NetworkPlugin()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

NetworkPlugin::~NetworkPlugin()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}
