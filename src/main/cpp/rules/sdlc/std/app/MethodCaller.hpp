
#ifndef RULES_SDLC_STD_APP_METHODCALLER_HPP
#define RULES_SDLC_STD_APP_METHODCALLER_HPP

#include <boost/exception/diagnostic_information.hpp>
#include <boost/signals2.hpp>
#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::app
{
template < typename FunctionSig, typename DispatchPolicy >

class MethodCaller;

template < typename Ret, typename... Args, typename DispatchPolicy >
class CFS_API_EXPORT MethodCaller< Ret ( Args... ), DispatchPolicy >
{
    LOG4CXX_DECLARE_STATIC_LOGGER

public:
    using signal_type = boost::signals2::signal< Ret ( Args... ), DispatchPolicy >;
    using result_type = Ret;

    MethodCaller ( );

    Ret
        operator( ) ( Args &&... args )
    {
        return m_signal ( std::forward< Args > ( args )... );
    }
    signal_type m_signal;
};

template < typename... Args, typename DispatchPolicy >
class CFS_API_EXPORT MethodCaller< void ( Args... ), DispatchPolicy >
{
    LOG4CXX_DECLARE_STATIC_LOGGER

public:
    using signal_type = boost::signals2::signal< void ( Args... ), DispatchPolicy >;
    using result_type = void;

    MethodCaller ( ) { }
    void
        operator( ) ( Args &&... args )
    {
        m_signal ( std::forward< Args > ( args )... );
    }
    signal_type m_signal;
};

}     // namespace cfs::utils::app

#endif
