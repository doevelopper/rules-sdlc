
#include <com/github/doevelopper/rules/sdlc/app/utils/Semaphore.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

log4cxx::LoggerPtr Semaphore::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.Semaphore"));

Semaphore::Semaphore()
    : m_mutex()
    , m_cv()
    , m_permits(1)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Semaphore::~Semaphore()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Semaphore::Semaphore(int permits)
    : m_mutex()
    , m_cv()
    , m_permits(permits)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void Semaphore::release()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_permits += 1;
    m_cv.notify_one();
}

void Semaphore::acquire()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_cv.wait(lock, [this] { return m_permits != 0; });
    m_permits -= 1;
}
