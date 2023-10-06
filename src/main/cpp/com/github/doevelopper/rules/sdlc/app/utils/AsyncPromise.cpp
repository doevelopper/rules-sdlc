
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncPromise.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

template <typename ResultType>
log4cxx::LoggerPtr AsyncPromise<ResultType>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.AsyncPromise"));

template <typename ResultType>
AsyncPromise<ResultType>::AsyncPromise()
    : m_sstoken()
    , m_promise()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename ResultType>
AsyncPromise<ResultType>::~AsyncPromise()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

// template <typename ResultType>
// AsyncPromise<ResultType>::AsyncPromise(AsyncPromise<ResultType> && other) = default;

template <typename ResultType>
bool AsyncPromise<ResultType>::stop_requested() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_sstoken.stop_requested();
}

template <typename ResultType>
void AsyncPromise<ResultType>::set_result(ResultType value)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_promise.set_value(value);
}

template <typename ResultType>
AsyncRequest<ResultType> AsyncPromise<ResultType>::get_request()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::stop_source ssource;
    m_sstoken = ssource.get_token();
    return AsyncRequest<ResultType>(std::move(ssource), m_promise.get_future());
}
