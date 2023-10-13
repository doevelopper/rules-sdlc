
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_INTERNAL_APPLICATIONPRIVATE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_INTERNAL_APPLICATIONPRIVATE_HPP

#include <com/github/doevelopper/rules/sdlc/app/PluginInterface.hpp>
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/Version.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/asio/signal_set.hpp>

#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <typeindex>
#include <unordered_map>

namespace com::github::doevelopper::rules::sdlc::app::internal
{
    using AnyTypeCmpMap =
        std::unordered_map<std::type_index, std::function<bool(const boost::any & a, const boost::any & b)>>;

    class SDLC_API_EXPORT ApplicationPrivate
    {
        Q_DISABLE_COPY_MOVE(ApplicationPrivate)
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        ApplicationPrivate();
        virtual ~ApplicationPrivate();

        std::string version() const;
        std::string fullVersionInfo() const;
        std::filesystem::path dataDirectory() const;
        void dataDirectory(const std::filesystem::path dir = "data") const;
        std::filesystem::path configDirectory() const;
        void configDirectory(const std::filesystem::path & dir = "conf");

    protected:
    private:
        com::github::doevelopper::rules::sdlc::logging::LoggingService * m_loggerService;
        com::github::doevelopper::rules::sdlc::app::OptionDesc m_appplicationOptions;
        com::github::doevelopper::rules::sdlc::app::OptionDesc m_appplicationConfigOptions;
        com::github::doevelopper::rules::sdlc::app::OptionMap m_optionMap;
        std::filesystem::path m_data_dir {"data"};
        std::filesystem::path m_config_dir {"conf"};
        std::filesystem::path m_logging_conf {"logging.json"};
        std::filesystem::path m_config_file_name;
        std::atomic_bool m_is_quiting {false};
        AnyTypeCmpMap m_anyCompareMap;

        static const unsigned long LOGGER_WATCH_DELAY;
    };

} // namespace com::github::doevelopper::rules::sdlc::app

#endif
