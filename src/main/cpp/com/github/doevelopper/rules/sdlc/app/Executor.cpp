
#include <com/github/doevelopper/rules/sdlc/app/ExecutionContext.hpp>
#include <com/github/doevelopper/rules/sdlc/app/Executor.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr Executor::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.Executor"));

/*
   Executor::Executor()
   : m_context()
   , m_priority(75)
   {
   LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
   }
 */

Executor::Executor(ExecutionContext & q, int p)
    : m_context(q)
    , m_priority(p)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Executor::~Executor()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

ExecutionContext & Executor::context() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (m_context);
}

template <typename Function, typename Allocator>
void Executor::dispatch(Function f, const Allocator &) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_context.add(m_priority, std::move(f));
}

template <typename Function, typename Allocator>
void Executor::post(Function f, const Allocator &) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_context.add(m_priority, std::move(f));
}

template <typename Function, typename Allocator>
void Executor::defer(Function f, const Allocator &) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_context.add(m_priority, std::move(f));
}

void Executor::on_work_started() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void Executor::on_work_finished() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
