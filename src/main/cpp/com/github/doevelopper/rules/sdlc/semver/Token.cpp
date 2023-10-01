#include <com/github/doevelopper/rules/sdlc/semver/Token.hpp>

using namespace com::github::doevelopper::rules::sdlc::semver;

log4cxx::LoggerPtr Token::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.semver.Token"));

Token::Token() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Token::~Token() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
