
#include <rules/sdlc/common/app/OptionDescription.hpp>

using namespace rules::sdlc::stdc::app;

OptionDescription::OptionDescription() { }

OptionDescription::OptionDescription(boost::shared_ptr<boost::program_options::option_description> option) noexcept { }

OptionDescription::~OptionDescription() { }

void OptionDescription::usage() { }

void OptionDescription::checkIfPositional(const boost::program_options::positional_options_description & positionalDesc)
{
}
