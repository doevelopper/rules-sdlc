
#include <rules/sdlc/std/logging/CentralizedLogging.hpp>

using namespace cfs::utils::log;

log4cxx::LoggerPtr CentralizedLogging::logger = log4cxx::Logger::getLogger (
    std::string ( "cfs.utils.log.CentralizedLogging" ) );

CentralizedLogging::CentralizedLogging ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }

CentralizedLogging::~CentralizedLogging ( ) { LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ ); }
