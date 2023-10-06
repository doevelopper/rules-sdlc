
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncRequest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

template <typename ResultType>
log4cxx::LoggerPtr AsyncRequest<ResultType>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.AsyncRequest"));

template <typename ResultType>
AsyncRequest<ResultType>::AsyncRequest()
    : m_ssource()
    , m_result()
    , m_then_thread()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename ResultType>
AsyncRequest<ResultType>::~AsyncRequest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_ssource.request_stop();
}

template <typename ResultType>
AsyncRequest<ResultType>::AsyncRequest(std::stop_source ssource, std::future<ResultType> result)
    : m_ssource(std::move(ssource))
    , m_result(std::move(result))
    , m_then_thread()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename ResultType>
void AsyncRequest<ResultType>::cancel()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_ssource.request_stop();
}

template <typename ResultType>
bool AsyncRequest<ResultType>::is_ready() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_result.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}

template <typename ResultType>
ResultType AsyncRequest<ResultType>::await()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_result.get();
}

template <typename ResultType>
void AsyncRequest<ResultType>::wait()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_result.wait();
}

template <typename ResultType>
template <typename Func>
void AsyncRequest<ResultType>::then(Func func)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_then_thread = std::jthread([this, func = std::move(func)](std::stop_token sstoken) mutable {
        try
        {
            ResultType result = m_result.get();
            if (!m_ssource.stop_requested())
            {
                // exceptions here will cause terminate()
                if constexpr (std::is_invocable<Func, std::stop_token, ResultType>::value)
                {
                    func(sstoken, std::move(result));
                }
                else
                {
                    func(std::move(result));
                }
            }
        }
        catch (std::future_error const & err)
        {
            // ignore, request got canceled
        }
    });
}
