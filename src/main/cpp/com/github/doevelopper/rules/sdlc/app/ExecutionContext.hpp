
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTIONCONTEXT_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_EXECUTIONCONTEXT_HPP

#include <com/github/doevelopper/rules/sdlc/app/Executor.hpp>
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandler.hpp>
#include <boost/asio.hpp>

#include <queue>

namespace com::github::doevelopper::rules::sdlc::app
{

    struct Priority
    {
        static constexpr int LOWEST      = std::numeric_limits<int>::min();
        static constexpr int LOW         = 10;
        static constexpr int MEDIUM_LOW  = 25;
        static constexpr int MEDIUM      = 50;
        static constexpr int MEDIUM_HIGH = 75;
        static constexpr int HIGH        = 100;
        static constexpr int HIGHEST     = std::numeric_limits<int>::max();
    };

    class SDLC_API_EXPORT ExecutionContext : public boost::asio::execution_context
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
        struct derefLess
        {
            template <typename Pointer>
            bool operator()(const Pointer & a, const Pointer & b) noexcept(noexcept(*a < *b))
            {
                return *a < *b;
            }
        };

    public:

        ExecutionContext();
        ExecutionContext(const ExecutionContext &)             = default;
        ExecutionContext(ExecutionContext &&)                  = default;
        ExecutionContext & operator=(const ExecutionContext &) = default;
        ExecutionContext & operator=(ExecutionContext &&)      = default;
        virtual ~ExecutionContext();

        template <typename Function>
        boost::asio::executor_binder<Function, Executor> wrap(int priority, Function && func)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            return boost::asio::bind_executor(Executor(*this, priority), std::forward<Function>(func));
        }

        template <typename F>
        void add(int priority, F function)
        {
            LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
            std::unique_ptr<QueuedHandleBase> handler(new QueuedHandler<F>(priority, --m_order, std::move(function)));
            m_handlers.push(std::move(handler));
        }

        void executeAll();
        bool executeHighest();
        std::size_t size();

    protected:
    private:

        std::priority_queue<std::unique_ptr<QueuedHandleBase>, std::deque<std::unique_ptr<QueuedHandleBase>>, derefLess>
            m_handlers;
        std::size_t m_order =
            std::numeric_limits<std::size_t>::max(); // to maintain FIFO ordering in queue within priority
    };
} // namespace com::github::doevelopper::rules::sdlc::app

#endif
