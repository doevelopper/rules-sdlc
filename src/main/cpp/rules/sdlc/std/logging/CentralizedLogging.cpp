
#include <rules/sdlc/std/logging/CentralizedLogging.hpp>

using namespace rules::sdlc::stdc::logging;

log4cxx::LoggerPtr CentralizedLogging::logger = log4cxx::Logger::getLogger (
    std::string ( "rules.sdlc.stdc.log.CentralizedLogging" ) );

CentralizedLogging::CentralizedLogging ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }

CentralizedLogging::~CentralizedLogging ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }
