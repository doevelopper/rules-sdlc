
#include <com/github/doevelopper/rules/sdlc/app/TimeoutGuard.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr TimeoutGuard::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.TimeoutGuard"));

TimeoutGuard::TimeoutGuard() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeoutGuard::TimeoutGuard(clock::duration timeout, std::function<void(void)> alarm, clock::duration naptime)
    : m_timeout(timeout)
    , m_alarm(alarm)
    , m_naptime(naptime)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeoutGuard::TimeoutGuard(clock::duration timeout, std::function<void(void)> alarm)
    : TimeoutGuard(timeout, alarm, timeout)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeoutGuard::~TimeoutGuard() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_live.store(false);
    this->m_wakeup.notify_all();
    // this->m_guard_thread.join();
}

void TimeoutGuard::guard()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    while (this->m_live.load())
    {
        if (this->m_idle.load())
        {
            LOG4CXX_DEBUG(logger, "Sleep indefinitely until either told to become active or destruct");
            std::unique_lock<std::mutex> live_lock(this->m_guard_mutex);
            this->m_wakeup.wait(live_lock, [this]() { return !this->m_idle.load() || !this->m_live.load(); });
        };

        LOG4CXX_DEBUG(logger, "Quit the loop if destructing");

        if (!this->m_live.load())
            break;

        LOG4CXX_DEBUG(logger, "The actual timeout checking");

        auto now = clock::now();

        if ((now - this->m_touched.load()) > this->m_timeout)
        {
            this->m_idle.store(true);
            this->m_alarm();
            LOG4CXX_DEBUG(logger, "Skip waiting for next timeout");
            continue;
        }

        {
            LOG4CXX_DEBUG(logger, "sleep until next timeout check or destruction");
            std::unique_lock<std::mutex> live_lock(this->m_guard_mutex);
            this->m_wakeup.wait_for(live_lock, this->m_naptime, [this]() { return !this->m_live.load(); });
        }
    };
}

void TimeoutGuard::watch()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->touch();
    this->m_idle.store(false);
    this->m_wakeup.notify_all();
}

void TimeoutGuard::touch()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    this->m_touched.store(clock::now());
}
