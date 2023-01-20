
#ifndef RULES_SDLC_STD_APP_OPTIONDESCRIPTION_HPP
#define RULES_SDLC_STD_APP_OPTIONDESCRIPTION_HPP

#include <boost/program_options.hpp>
#include <boost/variant/get.hpp>
#include <boost/variant/variant.hpp>

#include <string>

#include <rules/sdlc/common/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::app
{

    class SDLC_API_EXPORT OptionDescription
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        class OptionPrinter
        {
        public:

            void addOption(const OptionDescription & optionDesc);
            std::string usage();
            std::string positionalOptionDetails();
            std::string optionDetails();

        public:

            static void printStandardAppDesc(
                const std::string & appName, std::ostream & out, boost::program_options::options_description desc,
                boost::program_options::positional_options_description * positionalDesc = nullptr);
            static void formatRequiredOptionError(boost::program_options::required_option & error);

        private:

            // std::vector< CustomOptionDescription > options_;
            // std::vector< CustomOptionDescription > positionalOptions_;
        };

        OptionDescription() noexcept;
        OptionDescription(boost::shared_ptr<boost::program_options::option_description> option) noexcept;
        OptionDescription(const OptionDescription &) noexcept = default;
        OptionDescription(OptionDescription &&) noexcept = default;
        OptionDescription & operator=(const OptionDescription &) noexcept = default;
        OptionDescription & operator=(OptionDescription &&) noexcept = default;
        virtual ~OptionDescription();

        void usage();
        void checkIfPositional(const boost::program_options::positional_options_description & positionalDesc);

    protected:
    private:

        std::string m_optionID;
        std::string m_optionDisplayName;
        std::string m_optionDescription;
        std::string m_optionFormatName;

        bool m_required;
        bool m_hasShort;
        bool m_hasArgument;
        bool m_isPositional;
    };
}
#endif
