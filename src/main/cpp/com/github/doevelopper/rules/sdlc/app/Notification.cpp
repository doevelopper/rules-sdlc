#include <com/github/doevelopper/rules/sdlc/app/Notification.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::logging;

template <typename T>
log4cxx::LoggerPtr Notification<T>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.Notification"));

template <typename T>
Notification<T>::Notification() noexcept
    : m_notified(false)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename T>
Notification<T>::~Notification() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename T>
void Notification<T>::notify(T t)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Need to move functions to local so that we can invoke
    // them outside of mutex in the event that invoking them
    // deletes this instance and thus the mutex.
    std::vector<std::function<void(T)>> functions;

    m_mutex.lock();

    // Copy 't' rather than 'std::move' so that we can use 't' when
    // invoking the functions in case one of the callbacks deletes
    // this instance.
    m_typename = t;

    m_notified.store(true, std::memory_order_release);

    m_condition.notify_all();

    functions = std::move(m_functions);

    m_mutex.unlock();

    // NOTE: explicit design goal to execute handlers in reverse order
    // they were added. This works similar to how destructors are
    // called on the stack in reverse order to get constructed.
    while (!functions.empty())
    {
        // See comment above for why we use 't' instead of 't_'.
        functions.back()(t);
        functions.pop_back();
    }
}

template <typename T>
void Notification<T>::watch(std::function<void(T)> && f)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_notified.load(std::memory_order_acquire))
    {
        f(m_typename);
    }
    else
    {
        m_mutex.lock();
        if (m_notified.load(std::memory_order_acquire))
        {
            m_mutex.unlock();
            f(m_typename);
        }
        else
        {
            m_functions.push_back(std::move(f));
            m_mutex.unlock();
        }
    }
}

template <typename T>
T Notification<T>::wait()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (!m_notified.load(std::memory_order_acquire))
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (!m_notified.load(std::memory_order_acquire))
        {
            m_condition.wait(lock);
        }
    }
    return m_typename;
}
