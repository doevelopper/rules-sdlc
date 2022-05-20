
#include <rules/sdlc/std/CustomEnvironment.hpp>

using namespace rules::sdlc::stdc;
using namespace rules::sdlc::stdc::test;

log4cxx::LoggerPtr CustomEnvironment::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdtest.CustomEnvironment"));

CustomEnvironment::CustomEnvironment()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

CustomEnvironment::~CustomEnvironment()
{
    //FIXME: No appender could be found for logger
    //LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void CustomEnvironment::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void CustomEnvironment::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}
