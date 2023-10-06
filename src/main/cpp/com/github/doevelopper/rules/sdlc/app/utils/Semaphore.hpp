#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORE_HPP

#include <chrono>
#include <condition_variable>
#include <mutex>

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::app::utils
{

    class Semaphore
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Semaphore();
        Semaphore(int permits);
        ~Semaphore();
        void release();
        void acquire();

    protected:
    private:

        std::mutex m_mutex;
        std::condition_variable m_cv;
        int m_permits;

        Semaphore(const Semaphore &)             = delete;
        Semaphore & operator=(const Semaphore &) = delete;
    };
}

#endif
