
#include <rules/sdlc/std/app/Channel.hpp>

using namespace rules::sdlc::stdc::app;

template < typename Data, typename DispatchPolicy >
log4cxx::LoggerPtr Channel< Data, DispatchPolicy >::logger =
    log4cxx::Logger::getLogger ( std::string ( "rules.sdlc.stdc.app.Channel" ) );

template < typename Data, typename DispatchPolicy >
log4cxx::LoggerPtr Channel< Data, DispatchPolicy >::Handle::logger =
    log4cxx::Logger::getLogger ( std::string ( "rules.sdlc.stdc.app.Handle" ) );

template < typename Data, typename DispatchPolicy >
Channel< Data, DispatchPolicy >::Channel ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
}

template < typename Data, typename DispatchPolicy >
Channel< Data, DispatchPolicy >::~Channel ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
}

template < typename Data, typename DispatchPolicy >
Channel< Data, DispatchPolicy >::Handle::Handle ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
}

template < typename Data, typename DispatchPolicy >
Channel< Data, DispatchPolicy >::Handle::~Handle ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    unsubscribe ( );
}

template < typename Data, typename DispatchPolicy >
Channel< Data, DispatchPolicy >::Handle::Handle ( HandleType && m_handle )
    : m_handle ( std::move ( m_handle ) )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
}

template < typename Data, typename DispatchPolicy >
void Channel< Data, DispatchPolicy >::Handle::unsubscribe ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    if ( m_handle.connected ( ) ) { m_handle.disconnect ( ); }
}

template < typename Data, typename DispatchPolicy >
bool Channel< Data, DispatchPolicy >::hasSubscribers ( )
{
    LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
    auto connections = m_signal.num_slots ( );
    return ( connections > 0 );
}
