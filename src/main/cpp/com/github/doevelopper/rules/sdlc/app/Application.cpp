

#include <com/github/doevelopper/rules/sdlc/app/Application.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::semver;

log4cxx::LoggerPtr Application::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.Application"));

Application::Application() noexcept
    : m_loggerService(nullptr)
    , m_version()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Application::~Application() noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_loggerService)
    {
        delete m_loggerService;
        m_loggerService = nullptr;
    }
}

int Application::start()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Application::Package::Package()
{
    LOG4CXX_TRACE(Application::logger, __LOG4CXX_FUNC__);
}

Application::Package::Package(std::string name)
{
    LOG4CXX_TRACE(Application::logger, __LOG4CXX_FUNC__);
}

Application::Package::~Package()
{
    LOG4CXX_TRACE(Application::logger, __LOG4CXX_FUNC__);
}

std::string Application::Package::pkgName()
{
    LOG4CXX_TRACE(Application::logger, __LOG4CXX_FUNC__);
}
