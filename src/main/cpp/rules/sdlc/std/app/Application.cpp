
#include <boost/algorithm/string.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/filesystem.hpp>
#include <rules/sdlc/std/app/Application.hpp>
#include <rules/sdlc/std/app/ApplicationPrivate.hpp>

#include <fstream>
#include <future>
#include <iostream>
#include <unordered_map>

using namespace rules::sdlc::stdc::app;

log4cxx::LoggerPtr Application::logger =
    log4cxx::Logger::getLogger ( std::string ( "rules.sdlc.stdc.app.Application" ) );

Application::Application ( )
    : d_ptr ( new ApplicationPrivate ( ) )
    , m_ioService ( std::make_shared< boost::asio::io_service > ( ) )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
    register_config_type< std::string > ( );
    register_config_type< bool > ( );
    register_config_type< unsigned short > ( );
    register_config_type< unsigned > ( );
    register_config_type< unsigned long > ( );
    register_config_type< unsigned long long > ( );
    register_config_type< short > ( );
    register_config_type< int > ( );
    register_config_type< long > ( );
    register_config_type< long long > ( );
    register_config_type< double > ( );
    register_config_type< std::vector< std::string > > ( );
    register_config_type< std::filesystem::path > ( );
}

Application::~Application ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
}

void Application::startup ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
    boost::asio::io_service startup_thread_ios;
    iOServiceSignalHandling ( startup_thread_ios, true );
    std::thread startup_thread ( [&startup_thread_ios] ( ) { startup_thread_ios.run ( ); } );

    auto clean_up_signal_thread = [&startup_thread_ios, &startup_thread] ( ) {
        startup_thread_ios.stop ( );
        startup_thread.join ( );
    };

    try
    {
        for ( auto plugin : m_initializedPlugins )
        {
            if ( is_quiting ( ) ) break;
            plugin->startup ( );
        }
    }
    catch ( ... )
    {
        clean_up_signal_thread ( );
        shutdown ( );
        throw;
    }

    // after startup, shut down the signal handling thread and catch the signals back on main io_service
    clean_up_signal_thread ( );
    iOServiceSignalHandling ( get_io_service ( ), false );

#ifdef SIGHUP
    std::shared_ptr< boost::asio::signal_set > sighup_set ( new boost::asio::signal_set ( get_io_service ( ), SIGHUP ) );
    startSighupHandler ( sighup_set );
#endif
}

void Application::shutdown ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
}

void Application::exec ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
}

void Application::quit ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
}

bool Application::is_quiting ( ) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    // Q_D( Application );
    return ( /*d->is_quiting*/ true );
}

boost::asio::io_service & Application::get_io_service ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
    return ( *m_ioService );
}

void Application::register_config_type_comparison ( std::type_index i, ConfigComparison comp )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );

    // d_ptr->_any_compare_map.emplace(i, comp);
}

void Application::plugin_initialized ( PluginInterface & plug )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
    m_initializedPlugins.push_back ( &plug );
}

void Application::plugin_started ( PluginInterface & plug )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    Q_D ( Application );
    m_runningPlugins.push_back ( &plug );
}

PluginInterface * Application::findPlugin ( const std::string & name ) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    // Q_D( Application );
    auto itr = m_plugins.find ( name );
    if ( itr == m_plugins.end ( ) ) { return nullptr; }
    return ( itr->second.get ( ) );
}

PluginInterface & Application::getPlugin ( const std::string & name ) const
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );

    // Q_D( Application );

    auto ptr = findPlugin ( name );
    if ( ! ptr ) { LOG4CXX_ERROR ( logger, "unable to find plugin: " << name ); }

    return ( *ptr );
}

void Application::set_thread_priority_max ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
#if __has_include( <pthread.h>)
    pthread_t          this_thread = pthread_self ( );
    struct sched_param params
    {
    };
    int policy = 0;
    int ret    = pthread_getschedparam ( this_thread, &policy, &params );

    if ( ret != 0 )
    {
        LOG4CXX_ERROR ( logger, "Unable to get thread priority" );
    }

    params.sched_priority = sched_get_priority_max ( policy );

    ret = pthread_setschedparam ( this_thread, policy, &params );

    if ( ret != 0 )
    {
        LOG4CXX_ERROR ( logger, "Unable to set thread priority" );
    }
#endif
}

void Application::waitForSignal ( std::shared_ptr< boost::asio::signal_set > ss )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    ss->async_wait ( [this, ss] ( const boost::system::error_code & ec, int ) {
        if ( ec )
        {
            LOG4CXX_DEBUG ( logger, "EC" );
            return;
        }
        quit ( );
        waitForSignal ( ss );
    } );
}

void Application::iOServiceSignalHandling ( boost::asio::io_service & ios, bool startup )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    std::shared_ptr< boost::asio::signal_set > ss = std::make_shared< boost::asio::signal_set > ( ios, SIGINT, SIGTERM );
#ifdef SIGPIPE
    ss->add ( SIGPIPE );
#endif
#ifdef SIGHUP
    if ( startup ) { ss->add ( SIGHUP ); }
#endif
    waitForSignal ( ss );
}

void Application::startSighupHandler ( std::shared_ptr< boost::asio::signal_set > sighup_set )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
#ifdef SIGHUP
    sighup_set->async_wait ( [sighup_set, this] ( const boost::system::error_code & err, int /*num*/ ) {
        if ( err ) return;
        /*
           app().post(priority::medium, [sighup_set, this]()
           {
             m_sighupCallback();
             for( auto plugin : m_initializedPlugins )
             {
                if( is_quiting() ) return;
                plugin->handle_sighup();
             }
           });
           startSighupHandler( sighup_set );
         */
    } );
#endif
}
