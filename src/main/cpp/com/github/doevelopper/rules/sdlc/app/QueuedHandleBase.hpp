
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLEBASE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLEBASE_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::app
{
    class QueuedHandleBase
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        QueuedHandleBase() noexcept;
        QueuedHandleBase(int p, size_t order);
        // QueuedHandleBase(const QueuedHandleBase &) noexcept             = default;
        // QueuedHandleBase(QueuedHandleBase &&) noexcept                  = default;
        // QueuedHandleBase & operator=(const QueuedHandleBase &) noexcept = default;
        // QueuedHandleBase & operator=(QueuedHandleBase &&) noexcept      = default;
        virtual ~QueuedHandleBase() noexcept;

        virtual void execute() = 0;
        int priority() const;

        friend bool operator<(const QueuedHandleBase & lhs, const QueuedHandleBase & rhs) noexcept
        {
            return std::tie(lhs.m_priority, lhs.m_order) < std::tie(rhs.m_priority, rhs.m_order);
        }

    protected:
    private:

        int m_priority;
        std::size_t m_order;
        Q_DISABLE_COPY_MOVE(QueuedHandleBase)
    };
}
#endif
