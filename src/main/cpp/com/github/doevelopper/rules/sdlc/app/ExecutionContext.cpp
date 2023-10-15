
#include <com/github/doevelopper/rules/sdlc/app/ExecutionContext.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr ExecutionContext::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.ExecutionContext"));

// template <typename F>
// log4cxx::LoggerPtr ExecutionContext::QueuedHandler<F>::logger =
//     log4cxx::Logger::getLogger(std::string("cfs.utils.app.ExecutionContext.QueuedHandler"));

// template <typename F>
// ExecutionContext::QueuedHandler<F>::QueuedHandler()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// template <typename F>
// ExecutionContext::QueuedHandler<F>::QueuedHandler(int p, std::size_t order, F f)
//     : QueuedHandleBase(p, order)
//     , m_function(std::move(f))
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// template <typename F>
// ExecutionContext::QueuedHandler<F>::~QueuedHandler()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// template <typename F>
// void ExecutionContext::QueuedHandler<F>::execute()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     m_function();
// }

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
