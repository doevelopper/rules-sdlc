#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNC_REQUEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNC_REQUEST_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <future>
#include <stop_token>
#include <thread>

namespace com::github::doevelopper::rules::sdlc::app::utils
{

    template <typename ResultType>
    class AsyncRequest
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        AsyncRequest();
        AsyncRequest(std::stop_source ssource, std::future<ResultType> result);
        AsyncRequest(AsyncRequest && other) = default;
        ~AsyncRequest();

        /** Cancel the request */
        void cancel();
        /** Check if the request has completed */
        bool is_ready() const;

        /** Wait for the request to complete and return the result. Must
            only be called once or 'std::future_error' will be thrown. Will
            throw if the request threw an exception. */
        ResultType await();

        /** Wait for the request to complete, will not throw. */
        void wait();

        /** Register a callback to be called once the request has completed */
        template <typename Func>
        void then(Func func);

    protected:

        std::stop_source m_ssource;
        std::future<ResultType> m_result;
        std::jthread m_then_thread;
    };

}

#endif
