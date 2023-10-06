
#include <com/github/doevelopper/rules/sdlc/app/OptionDescription.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
log4cxx::LoggerPtr OptionDescription::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.OptionDescription"));

OptionDescription::OptionDescription()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

OptionDescription::OptionDescription(boost::shared_ptr<boost::program_options::option_description> option) noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

OptionDescription::~OptionDescription()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

std::string OptionDescription::usage()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void OptionDescription::checkIfPositional(const boost::program_options::positional_options_description & positionalDesc)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
