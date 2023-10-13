
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
        QueuedHandleBase(const QueuedHandleBase &) noexcept             = default;
        QueuedHandleBase(QueuedHandleBase &&) noexcept                  = default;
        QueuedHandleBase & operator=(const QueuedHandleBase &) noexcept = default;
        QueuedHandleBase & operator=(QueuedHandleBase &&) noexcept      = default;
        virtual ~QueuedHandleBase() noexcept;

    protected:
    private:
    };
}
#endif
