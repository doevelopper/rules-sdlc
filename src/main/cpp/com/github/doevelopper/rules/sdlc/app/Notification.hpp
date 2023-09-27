
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_NOTIFICATION_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_NOTIFICATION_HPP

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <vector>

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::app
{
    /*!
     * @brief Provides a simple mechanism to receive notifications as callbacks @see
     *      [`absl::Notification`](https://abseil.io/docs/cpp/guides/synchronization#notification)
     * @tparam T
     */

    /*!
    @code{.cpp}
        com::github::doevelopper::rules::sdlc::app::Notification<std::string> notification;

        notification.Watch([](const std::string& s)
        {
            // Invoked when 'Notification::Notify()' gets invoked.
        });
        notification.notify("hello world");
    @endcode
    Block the current thread (***bewarned***) for the notification:
    @code{.cpp}
        com::github::doevelopper::rules::sdlc::app::Notification<std::string> notification;
        // Thread 1:
        auto s = notification.wait();

        // Thread 2:
        notification.notify("hello world");
    @endcode
    */
    template <typename T>
    class Notification
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Notification() noexcept;
        Notification(const Notification &) noexcept             = default;
        Notification(Notification &&) noexcept                  = default;
        Notification & operator=(const Notification &) noexcept = default;
        Notification & operator=(Notification &&) noexcept      = default;
        virtual ~Notification() noexcept;

        void notify(T t);
        void watch(std::function<void(T)> && f);
        T wait();

    protected:
    private:

        std::mutex m_mutex;
        std::condition_variable m_condition;
        T m_typename;
        std::once_flag m_notify;
        std::atomic<bool> m_notified;
        std::vector<std::function<void(T)>> m_functions;
    };
}
#endif
