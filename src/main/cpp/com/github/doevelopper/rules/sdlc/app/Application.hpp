
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_APPLICATION_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_APPLICATION_HPP

#include <com/github/doevelopper/rules/sdlc/semver/Version.hpp>

namespace com::github::doevelopper::rules::sdlc::app
{
    class SDLC_API_EXPORT Application
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

        struct Package
        {
            Package();
            Package(std::string name);
            ~Package();
            std::string root;
            std::string name;
            std::string version;
            std::string arch;
            std::string build;
            std::string tag;
            std::string pkgName();
        };

    public:

        Application() noexcept;
        Application(const Application &)             = delete;
        Application(Application &&)                  = delete;
        Application & operator=(const Application &) = delete;
        Application & operator=(Application &&)      = delete;
        virtual ~Application() noexcept;

        int start();

    protected:
    private:

        com::github::doevelopper::rules::sdlc::logging::LoggingService * m_loggerService;
        com::github::doevelopper::rules::sdlc::semver::Version<Package> * m_version;
    };
}
#endif
