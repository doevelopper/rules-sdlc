

#include <rules/sdlc/std/semver/VersionError.hpp>

using namespace rules::sdlc::stdc::semver;

log4cxx::LoggerPtr VersionError::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.semver.VersionError"));

VersionError::VersionError()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionError::VersionError(const char* message)
  : m_msg(message)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionError::VersionError(const std::string& message)
  : m_msg(message)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionError::~VersionError()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

// const char* VersionError::what() const noexcept
// {
//   return m_msg.c_str();
// }
