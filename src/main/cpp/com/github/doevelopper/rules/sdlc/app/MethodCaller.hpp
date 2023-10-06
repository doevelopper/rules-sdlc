
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_METHODCALLER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_METHODCALLER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include <boost/signals2.hpp>

namespace com::github::doevelopper::rules::sdlc::app
{
    template <typename FunctionSig, typename DispatchPolicy>

    class MethodCaller;

    template <typename Ret, typename... Args, typename DispatchPolicy>
    class SDLC_API_EXPORT MethodCaller<Ret(Args...), DispatchPolicy>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        using signal_type = boost::signals2::signal<Ret(Args...), DispatchPolicy>;
        using result_type = Ret;

        MethodCaller();

        Ret operator()(Args &&... args)
        {
            return m_signal(std::forward<Args>(args)...);
        }

        signal_type m_signal;
    };

    template <typename... Args, typename DispatchPolicy>
    class SDLC_API_EXPORT MethodCaller<void(Args...), DispatchPolicy>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        using signal_type = boost::signals2::signal<void(Args...), DispatchPolicy>;
        using result_type = void;

        MethodCaller() { }

        void operator()(Args &&... args)
        {
            m_signal(std::forward<Args>(args)...);
        }

        signal_type m_signal;
    };

} // namespace com::github::doevelopper::rules::sdlc::app

#endif
