
#include <com/github/doevelopper/rules/sdlc/app/Method.hpp>
using namespace com::github::doevelopper::rules::sdlc::app;

template <typename FunctionSig, typename DispatchPolicy>
log4cxx::LoggerPtr Method<FunctionSig, DispatchPolicy>::Handle::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.Handle"));

template <typename FunctionSig, typename DispatchPolicy>
log4cxx::LoggerPtr Method<FunctionSig, DispatchPolicy>::logger =
    log4cxx::Logger::getLogger(std::string("cfs.utils.app.Method"));

template <typename FunctionSig, typename DispatchPolicy>
Method<FunctionSig, DispatchPolicy>::Handle::Handle()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename FunctionSig, typename DispatchPolicy>
Method<FunctionSig, DispatchPolicy>::Handle::~Handle()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    unregister();
}

template <typename Data, typename DispatchPolicy>
Method<Data, DispatchPolicy>::Handle::Handle(HandleType && m_handle)
    : m_handle(std::move(m_handle))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename Data, typename DispatchPolicy>
void Method<Data, DispatchPolicy>::Handle::unregister()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    if (m_handle.connected())
    {
        m_handle.disconnect();
    }
}

template <typename FunctionSig, typename DispatchPolicy>
Method<FunctionSig, DispatchPolicy>::Method()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename FunctionSig, typename DispatchPolicy>
Method<FunctionSig, DispatchPolicy>::~Method()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
