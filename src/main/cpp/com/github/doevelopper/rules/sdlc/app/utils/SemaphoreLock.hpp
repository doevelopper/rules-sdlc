
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORE_LOCK_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORE_LOCK_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/Semaphore.hpp>

namespace com::github::doevelopper::rules::sdlc::app::utils
{

    class SemaphoreLock
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        // SemaphoreLock();
        SemaphoreLock(Semaphore & sem);
        ~SemaphoreLock();

    private:

        Semaphore & m_sem;

    private:

        SemaphoreLock(const SemaphoreLock &)             = delete;
        SemaphoreLock & operator=(const SemaphoreLock &) = delete;
    };
}

#endif
