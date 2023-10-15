
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLER_HPP

#include <com/github/doevelopper/rules/sdlc/app/QueuedHandleBase.hpp>

#include <queue>

namespace com::github::doevelopper::rules::sdlc::app
{
    template <typename F>
    class QueuedHandler : public QueuedHandleBase
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        QueuedHandler() noexcept;
        QueuedHandler(int p, size_t order, F f);
        QueuedHandler(const QueuedHandler &) noexcept             = default;
        QueuedHandler(QueuedHandler &&) noexcept                  = default;
        QueuedHandler & operator=(const QueuedHandler &) noexcept = default;
        QueuedHandler & operator=(QueuedHandler &&) noexcept      = default;
        virtual ~QueuedHandler() noexcept;

        void execute() override;

    protected:
    private:
        F m_function;
    };
}
#endif
