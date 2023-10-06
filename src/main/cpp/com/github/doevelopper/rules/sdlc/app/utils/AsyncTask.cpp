
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncTask.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

template <typename ResultType>
log4cxx::LoggerPtr AsyncTask<ResultType>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.AsyncTask"));

template <typename ResultType>
AsyncTask<ResultType>::AsyncTask()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename ResultType>
AsyncTask<ResultType>::~AsyncTask()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename ResultType>
template <typename Func>
AsyncTask<ResultType>::AsyncTask(Func func)
    : AsyncRequest<ResultType>()
    , m_thread()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    std::promise<ResultType> promise;
    this->m_result = promise.get_future();
    m_thread = std::jthread([promise = std::move(promise), func = std::move(func)](std::stop_token sstoken) mutable {
        try
        {
            if constexpr (std::is_same<ResultType, void>::value)
            {
                if constexpr (std::is_invocable<Func, std::stop_token>::value)
                {
                    func(sstoken);
                }
                else
                {
                    func();
                }
                promise.set_value();
            }
            else
            {
                if constexpr (std::is_invocable<Func, std::stop_token>::value)
                {
                    promise.set_value(func(sstoken));
                }
                else
                {
                    promise.set_value(func());
                }
            }
        }
        catch (...)
        {
            promise.set_exception(std::current_exception());
        }
    });
    this->m_ssource = m_thread.get_stop_source();
}
