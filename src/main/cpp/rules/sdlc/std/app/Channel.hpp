
#ifndef RULES_SDLC_STD_APP_CHANEL_HPP
#define RULES_SDLC_STD_APP_CHANEL_HPP

#include <boost/asio.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/signals2.hpp>
#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::app
{
using erased_channel_ptr = std::unique_ptr< void, void ( * ) ( void * ) >;
struct DropExceptions
{
    DropExceptions ( ) = default;
    using result_type  = void;

    template < typename InputIterator >
    result_type
        operator( ) ( InputIterator first, InputIterator last )
    {
        while ( first != last )
        {
            try
            {
                *first;
            }
            catch ( ... )
            {
                // drop
            }
            ++first;
        }
    }
};

template < typename Data, typename DispatchPolicy >
class CFS_API_EXPORT Channel final
{

    LOG4CXX_DECLARE_STATIC_LOGGER

public:
    class Handle
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        Handle ( );
        Handle ( const Handle & ) = default;
        Handle ( Handle && )      = default;
        Handle &
            operator= ( const Handle & ) = delete;
        Handle &
            operator= ( Handle && ) = delete;
        virtual ~Handle ( );

        void
            unsubscribe ( );

    protected:
    private:
        using HandleType = boost::signals2::connection;
        HandleType m_handle;
        Handle ( HandleType && m_handle );
        friend class Channel;
    };

    Channel ( const Channel & ) = default;
    Channel ( Channel && )      = default;
    Channel &
        operator= ( const Channel & ) = default;
    Channel &
        operator= ( Channel && ) = default;

    void
        publish ( int priority, const Data & data );
    template < typename Callback >
    Handle
        subscribe ( Callback cb )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        return Handle ( m_signal.connect ( cb ) );
    }

    auto
        set_dispatcher ( const DispatchPolicy & policy )
            -> std::enable_if_t< std::is_copy_constructible< DispatchPolicy >::value, void >
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        m_signal.set_combiner ( policy );
    }

    bool
        hasSubscribers ( );

protected:
private:
    Channel ( );
    virtual ~Channel ( );
    static void
        deleter ( void * erased_channel_ptr )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        auto ptr = reinterpret_cast< Channel * > ( erased_channel_ptr );
        delete ( ptr );
    }

    static Channel *
        get_channel ( erased_channel_ptr & ptr )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        return ( reinterpret_cast< Channel * > ( ptr.get ( ) ) );
    }

    static erased_channel_ptr
        make_unique ( )
    {
        LOG4CXX_TRACE ( logger, __LOG4CXX_FUNC__ );
        return ( erased_channel_ptr ( new Channel ( ), &deleter ) );
    }

    boost::signals2::signal< void ( const Data & ), DispatchPolicy > m_signal;
    friend class Application;
};

/**
 *
 * @tparam Tag - API specific discriminator used to distinguish between otherwise identical data types
 * @tparam Data - the typ of the Data the channel carries
 * @tparam DispatchPolicy - The dispatch policy to use for this channel (defaults to @ref drop_exceptions)
 */
template < typename Tag, typename Data, typename DispatchPolicy = DropExceptions >
struct channel_decl
{
    using channel_type = Channel< Data, DispatchPolicy >;
    using tag_type     = Tag;
};

template < typename... Ts >
std::true_type
    is_channel_decl_impl ( const channel_decl< Ts... > * );

std::false_type
    is_channel_decl_impl ( ... );

template < typename T >
using is_channel_decl = decltype ( is_channel_decl_impl ( std::declval< T * > ( ) ) );
}     // namespace cfs::utils::app

#endif
