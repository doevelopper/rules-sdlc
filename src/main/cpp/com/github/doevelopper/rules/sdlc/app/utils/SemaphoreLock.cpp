
#include <com/github/doevelopper/rules/sdlc/app/utils/SemaphoreLock.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

log4cxx::LoggerPtr SemaphoreLock::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.SemaphoreLock"));

// SemaphoreLock::SemaphoreLock()
//     // : m_sem()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

SemaphoreLock::~SemaphoreLock()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_sem.release();
}

SemaphoreLock::SemaphoreLock(Semaphore & sem)
    : m_sem(sem)
{
    m_sem.acquire();
}
