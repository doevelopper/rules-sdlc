
#include <com/github/doevelopper/rules/sdlc/app/ExecutionContext.hpp>
using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr ExecutionContext::logger = log4cxx::Logger::getLogger(std::string("cfs.utils.app.ExecutionContext"));

log4cxx::LoggerPtr ExecutionContext::QueuedHandleBase::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.ExecutionContext.QueuedHandleBase"));

template <typename F>
log4cxx::LoggerPtr ExecutionContext::QueuedHandler<F>::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.ExecutionContext.QueuedHandler"));

log4cxx::LoggerPtr ExecutionContext::Executor::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.ExecutionContext.Executor"));

/*
   ExecutionContext::Executor::Executor()
   : m_context()
   , m_priority(75)
   {
   LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
   }
 */
ExecutionContext::Executor::Executor(ExecutionContext & q, int p)
    : m_context(q)
    , m_priority(p)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ExecutionContext::Executor::~Executor()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ExecutionContext & ExecutionContext::Executor::context() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (m_context);
}

ExecutionContext::QueuedHandleBase::QueuedHandleBase()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ExecutionContext::QueuedHandleBase::QueuedHandleBase(int p, std::size_t order)
    : m_priority(p)
    , m_order(order)
{
}

ExecutionContext::QueuedHandleBase::~QueuedHandleBase()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

int ExecutionContext::QueuedHandleBase::priority() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (m_priority);
}

template <typename F>
ExecutionContext::QueuedHandler<F>::QueuedHandler()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename F>
ExecutionContext::QueuedHandler<F>::QueuedHandler(int p, std::size_t order, F f)
    : QueuedHandleBase(p, order)
    , m_function(std::move(f))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename F>
ExecutionContext::QueuedHandler<F>::~QueuedHandler()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename F>
void ExecutionContext::QueuedHandler<F>::execute()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_function();
}

ExecutionContext::ExecutionContext()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ExecutionContext::~ExecutionContext()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void ExecutionContext::executeAll()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    while (!m_handlers.empty())
    {
        m_handlers.top()->execute();
        m_handlers.pop();
    }
}

bool ExecutionContext::executeHighest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    while (!m_handlers.empty())
    {
        m_handlers.top()->execute();
        m_handlers.pop();
    }
    return !m_handlers.empty();
}

std::size_t ExecutionContext::size()
{
    return (m_handlers.size());
}
