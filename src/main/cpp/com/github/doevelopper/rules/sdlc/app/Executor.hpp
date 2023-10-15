
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTOR_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTOR_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <boost/asio.hpp>

#include <queue>

namespace com::github::doevelopper::rules::sdlc::app
{
    class ExecutionContext;

    class Executor
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        Executor()                                      = delete;
        Executor(const Executor &) noexcept             = default;
        Executor(Executor &&) noexcept                  = default;
        Executor & operator=(const Executor &) noexcept = default;
        Executor & operator=(Executor &&) noexcept      = default;
        virtual ~Executor() noexcept;

        Executor(ExecutionContext & q, int p);
        ExecutionContext & context() const noexcept;

        template <typename Function, typename Allocator>
        void dispatch(Function f, const Allocator &) const;

        template <typename Function, typename Allocator>
        void post(Function f, const Allocator &) const;
        template <typename Function, typename Allocator>
        void defer(Function f, const Allocator &) const;
        void on_work_started() const noexcept;
        void on_work_finished() const noexcept;

        bool operator==(const Executor & rhs) const noexcept
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            return (&m_context == &rhs.m_context) && (m_priority == rhs.m_priority);
        }

        bool operator!=(const Executor & rhs) const noexcept
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            return !operator==(rhs);
        }

    protected:
    private:

        ExecutionContext & m_context;
        int m_priority;
    };
}
#endif
