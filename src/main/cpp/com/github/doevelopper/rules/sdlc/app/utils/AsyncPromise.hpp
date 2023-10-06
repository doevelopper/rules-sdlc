
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNC_PROMISE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNC_PROMISE_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncRequest.hpp>
#include <future>
#include <stop_token>
#include <thread>

namespace com::github::doevelopper::rules::sdlc::app::utils
{

    template <typename ResultType>
    class AsyncPromise
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        AsyncPromise();
        AsyncPromise(AsyncPromise<ResultType> && other) = default;
        ~AsyncPromise();

        bool stop_requested() const;
        void set_result(ResultType value);
        AsyncRequest<ResultType> get_request();

    private:

        std::stop_token m_sstoken;
        std::promise<ResultType> m_promise;
    };

}

#endif
