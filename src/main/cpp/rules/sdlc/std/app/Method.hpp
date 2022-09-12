
#ifndef RULES_SDLC_STD_APP_METHOD_HPP
#define RULES_SDLC_STD_APP_METHOD_HPP

#include <rules/sdlc/std/app/MethodCaller.hpp>

namespace rules::sdlc::stdc::app
{
using ErasedMethod = std::unique_ptr< void, void ( * ) ( void * ) >;
template < typename FunctionSig >
struct FirstSuccessPolicy;

template < typename Ret, typename... Args >
struct FirstSuccessPolicy< Ret ( Args... ) >
{
    using result_type = Ret;
    template < typename InputIterator >
    Ret operator( ) ( InputIterator first, InputIterator last )
    {
        std::string err;
        while ( first != last )
        {
            try
            {
                return *first;     // de-referencing the iterator causes the provider to run
            }
            catch ( ... )
            {
                if ( ! err.empty ( ) ) { err += "\",\""; }

                err += boost::current_exception_diagnostic_information ( );
            }
            ++first;
        }

        throw std::length_error ( std::string ( "No Result Available, All providers returned exceptions[" ) + err + "]" );
    }
};

template < typename... Args >
struct FirstSuccessPolicy< void ( Args... ) >
{
    using result_type = void;
    template < typename InputIterator >
    void
        operator( ) ( InputIterator first, InputIterator last )
    {
        std::string err;

        while ( first != last )
        {
            try
            {
                *first;     // de-referencing the iterator causes the provider to run
            }
            catch ( ... )
            {
                if ( ! err.empty ( ) ) { err += "\",\""; }

                err += boost::current_exception_diagnostic_information ( );
            }
            ++first;
        }
        throw std::length_error ( std::string ( "No Result Available, All providers returned exceptions[" ) + err + "]" );
    }
};

template < typename FunctionSig >
struct FirstProviderPolicy;

template < typename Ret, typename... Args >
struct FirstProviderPolicy< Ret ( Args... ) >
{
    using result_type = Ret;
    template < typename InputIterator >
    Ret operator( ) ( InputIterator first, InputIterator )
    {
        return *first;
    }
};

template < typename... Args >
struct FirstProviderPolicy< void ( Args... ) >
{
    using result_type = void;
    template < typename InputIterator >
    void operator( ) ( InputIterator first, InputIterator )
    {
        *first;
    }
};

template < typename FunctionSig, typename DispatchPolicy >

class SDLC_API_EXPORT Method final : public MethodCaller< FunctionSig, DispatchPolicy >
{
    LOG4CXX_DECLARE_STATIC_LOGGER

    class Handle
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:
        Handle ( );
        Handle ( const Handle & ) = default;
        Handle ( Handle && )      = default;
        Handle & operator= ( const Handle & ) = default;
        Handle & operator= ( Handle && ) = default;
        virtual ~Handle ( );

        void unregister ( );

    protected:
    private:
        using HandleType = boost::signals2::connection;
        HandleType m_handle;
        Handle ( HandleType && m_handle );
        friend class Method;
    };

    Method ( const Method & ) = default;
    Method ( Method && )      = default;
    Method & operator= ( const Method & ) = default;
    Method & operator= ( Method && ) = default;

    template < typename T >
    Handle registerProvider ( T provider, int priority = 0 )
    {
        return Handle ( this->m_signal.connect ( priority, provider ) );
    }

protected:
    Method ( );
    virtual ~Method ( );

    static void deleter ( void * ErasedMethod )
    {
        auto ptr = reinterpret_cast< Method * > ( ErasedMethod );
        delete ptr;
    }
    static Method * get_method ( ErasedMethod & ptr )
    {
        return reinterpret_cast< Method * > ( ptr.get ( ) );
    }
    static ErasedMethod make_unique ( )
    {
        return ErasedMethod ( new Method ( ), &deleter );
    }
    friend class Application;
};

template < typename Tag, typename FunctionSig, template < typename > class DispatchPolicy = FirstSuccessPolicy >
struct method_decl
{
    using method_type = Method< FunctionSig, DispatchPolicy< FunctionSig > >;
    using tag_type    = Tag;
};

template < typename Tag, typename FunctionSig, template < typename > class DispatchPolicy >
std::true_type
    is_method_decl_impl ( const method_decl< Tag, FunctionSig, DispatchPolicy > * );

std::false_type
    is_method_decl_impl ( ... );

template < typename T >
using is_method_decl = decltype ( is_method_decl_impl ( std::declval< T * > ( ) ) );
}
#endif
