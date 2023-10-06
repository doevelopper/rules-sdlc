
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNC_TASK_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNC_TASK_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncRequest.hpp>

namespace com::github::doevelopper::rules::sdlc::app::utils
{

    template <typename ResultType>
    class AsyncTask : public AsyncRequest<ResultType>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        AsyncTask() noexcept;
        ~AsyncTask() noexcept;
        template <typename Func>
        AsyncTask(Func func);

    private:

        std::jthread m_thread;
    };

}

#endif
