
#ifndef RULES_SDLC_STD_APP_APPLICATION_HPP
#define RULES_SDLC_STD_APP_APPLICATION_HPP

#include <boost/core/demangle.hpp>
#include <rules/sdlc/std/PimplPtr.hpp>
#include <rules/sdlc/std/app/Channel.hpp>
#include <rules/sdlc/std/app/ExecutionContext.hpp>
#include <rules/sdlc/std/app/Method.hpp>
#include <rules/sdlc/std/app/Plugin.hpp>
#include <rules/sdlc/std/semver/Version.hpp>

#include <filesystem>
#include <typeindex>

namespace rules::sdlc::stdc::app
{

class ApplicationPrivate;

class SDLC_API_EXPORT Application
{
    LOG4CXX_DECLARE_STATIC_LOGGER

    struct Package
    {
        Package ( );
        Package ( std::string name );
        ~Package ( );
        std::string root;
        std::string name;
        std::string version;
        std::string arch;
        std::string build;
        std::string tag;
        std::string
            pkgName ( );
    };

public:
    using ConfigComparison = std::function< bool ( const boost::any & a, const boost::any & b ) >;

    virtual ~Application ( );

    Application ( int & argc, char ** argv );
    void
        signalHangUpCallBack ( std::function< void ( ) > callback );

    template < typename... Plugin >
    bool
        initialize ( int argc, char ** argv )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        Q_D ( Application );

        // return(true);
        return ( initialize ( argc, argv, { findPlugin< Plugin > ( )... } ) );
    }
    void
        startup ( );
    void
        shutdown ( );
    void
        exec ( );
    void
        quit ( );
    bool
        is_quiting ( ) const;

    template < typename T >
    void
        register_config_type ( )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        register_config_type_comparison ( typeid ( T ), [] ( const auto & a, const auto & b ) {
            return boost::any_cast< const T & > ( a ) == boost::any_cast< const T & > ( b );
        } );
    }

    void
        register_config_type_comparison ( std::type_index, ConfigComparison comp );

    PluginInterface *
        findPlugin ( const std::string & name ) const;
    PluginInterface &
        getPlugin ( const std::string & name ) const;

    template < typename Plugin >
    auto &
        register_plugin ( )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        auto existing = findPlugin< Plugin > ( );
        if ( existing ) return ( *existing );

        auto plug = new Plugin ( );
        m_plugins[plug->name ( )].reset ( plug );
        plug->registerPlugings ( );
        return ( *plug );
    }

    template < typename Plugin >
    Plugin *
        findPlugin ( ) const
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        std::string name = boost::core::demangle ( typeid ( Plugin ).name ( ) );
        return dynamic_cast< Plugin * > ( findPlugin ( name ) );
    }

    template < typename Plugin >
    Plugin &
        getPlugin ( ) const
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        auto ptr = findPlugin< Plugin > ( );
        return ( *ptr );
    }

    template < typename MethodDecl >
    auto
        get_method ( ) -> std::enable_if_t< is_method_decl< MethodDecl >::value, typename MethodDecl::method_type & >
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        using method_type = typename MethodDecl::method_type;
        auto key          = std::type_index ( typeid ( MethodDecl ) );
        auto itr          = m_methods.find ( key );
        if ( itr != m_methods.end ( ) ) { return *method_type::get_method ( itr->second ); }
        else
        {
            m_methods.emplace ( std::make_pair ( key, method_type::make_unique ( ) ) );
            return *method_type::get_method ( m_methods.at ( key ) );
        }
    }

    template < typename ChannelDecl >
    auto
        get_channel ( ) -> std::enable_if_t< is_channel_decl< ChannelDecl >::value, typename ChannelDecl::channel_type & >
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        using channel_type = typename ChannelDecl::channel_type;
        auto key           = std::type_index ( typeid ( ChannelDecl ) );
        auto itr           = m_channels.find ( key );
        if ( itr != m_channels.end ( ) ) { return *channel_type::get_channel ( itr->second ); }
        else
        {
            m_channels.emplace ( std::make_pair ( key, channel_type::make_unique ( ) ) );
            return *channel_type::get_channel ( m_channels.at ( key ) );
        }
    }

    boost::asio::io_service &
        get_io_service ( );

    template < typename Func >
    auto
        post ( int priority, Func && func )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        return boost::asio::post ( *m_ioService, m_priQueue.wrap ( priority, std::forward< Func > ( func ) ) );
    }

    auto &
        get_priority_queue ( )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        return ( m_priQueue );
    }

    const boost::program_options::variables_map &
        get_options ( ) const;
    void
        set_thread_priority_max ( );

protected:
    template < typename Impl >
    friend class Plugin;
    bool
        initialize ( int argc, char ** argv, std::vector< PluginInterface * > autostartPlugins );

    void
        plugin_initialized ( PluginInterface & plug );
    void
        plugin_started ( PluginInterface & plug );

private:
    Application ( );

    void
        startSighupHandler ( std::shared_ptr< boost::asio::signal_set > sighup_set );
    void
        programOptions ( );
    void
        saveConfig ( const std::filesystem::path & cfg_file );
    void
        configFileContent ( std::ostream & os );
    void
        waitForSignal ( std::shared_ptr< boost::asio::signal_set > ss );
    void
        iOServiceSignalHandling ( boost::asio::io_service & ios, bool startup );

    std::shared_ptr< ApplicationPrivate >                       d_ptr;
    std::map< std::string, std::unique_ptr< PluginInterface > > m_plugins;
    std::vector< PluginInterface * >                            m_initializedPlugins;
    std::vector< PluginInterface * >                            m_runningPlugins;
    std::function< void ( ) >                                   m_sighupCallback;
    std::map< std::type_index, ErasedMethod >                   m_methods;
    std::map< std::type_index, erased_channel_ptr >             m_channels;
    std::shared_ptr< boost::asio::io_service >                  m_ioService;
    ExecutionContext                                            m_priQueue;

    Q_DECLARE_PRIVATE ( Application );
    Q_DISABLE_COPY_MOVE ( Application );
};

}

#endif
