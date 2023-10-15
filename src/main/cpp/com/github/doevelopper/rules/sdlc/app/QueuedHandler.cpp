
#include <com/github/doevelopper/rules/sdlc/app/QueuedHandler.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

template <typename F>
log4cxx::LoggerPtr QueuedHandler<F>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.QueuedHandler"));

template <typename F>
QueuedHandler<F>::QueuedHandler() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename F>
QueuedHandler<F>::QueuedHandler(int p, std::size_t order, F f)
    : QueuedHandleBase(p, order)
    , m_function(std::move(f))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename F>
QueuedHandler<F>::~QueuedHandler() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename F>
void QueuedHandler<F>::execute()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_function();
}
