
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_APPLICATION_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_APPLICATION_HPP

#include <typeindex>
#include <boost/algorithm/string.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/filesystem.hpp>

#include <com/github/doevelopper/rules/sdlc/app/ExecutionContext.hpp>
#include <com/github/doevelopper/rules/sdlc/app/Plugin.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/Version.hpp>

namespace com::github::doevelopper::rules::sdlc::app
{

    class ApplicationPrivate;

    class SDLC_API_EXPORT Application
    {
        std::shared_ptr<ApplicationPrivate> d_ptr;
        Q_DECLARE_PRIVATE(Application);
        Q_DISABLE_COPY_MOVE(Application);
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

        using ConfigComparison = std::function<bool(const boost::any & a, const boost::any & b)>;

        Application() noexcept;
        virtual ~Application() noexcept;
        Application(int & argc, char ** argv);

        int start();
        bool initialize(int argc, char ** argv);
        void signalHangUpCallBack(std::function<void()> callback);
        // void startup();
        // void shutdown();
        // void exec();
        // void quit();
        // bool is_quiting() const;
        void registerConfigTypeComparison(std::type_index, ConfigComparison comp);
        template <typename T>
        void registerConfigType(T type);

        PluginInterface * findPlugin(const std::string & name) const;
        PluginInterface & getPlugin(const std::string & name) const;

        template <typename Plugin>
        Plugin & getPlugin() const;
        template <typename Plugin>
        Plugin * findPlugin() const;

    protected:
    private:

        com::github::doevelopper::rules::sdlc::semver::Version<Package> * m_version;
        std::map<std::string, std::unique_ptr<PluginInterface>> m_plugins;
        std::vector<PluginInterface *> m_initializedPlugins;
        std::vector<PluginInterface *> m_runningPlugins;
        std::function<void()> m_sighupCallback;
        // std::map<std::type_index, ErasedMethod> m_methods;
        // std::map<std::type_index, erased_channel_ptr> m_channels;
        std::shared_ptr<boost::asio::io_service> m_ioService;
        ExecutionContext m_priQueue;
    };
}
#endif
