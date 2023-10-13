
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLER_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

#include <queue>

namespace com::github::doevelopper::rules::sdlc::app
{
    class QueuedHandler
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        QueuedHandler() noexcept;
        QueuedHandler(const QueuedHandler &) noexcept             = default;
        QueuedHandler(QueuedHandler &&) noexcept                  = default;
        QueuedHandler & operator=(const QueuedHandler &) noexcept = default;
        QueuedHandler & operator=(QueuedHandler &&) noexcept      = default;
        virtual ~QueuedHandler() noexcept;

    protected:
    private:
    };
}
#endif
