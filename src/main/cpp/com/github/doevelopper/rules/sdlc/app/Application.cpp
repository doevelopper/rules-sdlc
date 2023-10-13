

#include <com/github/doevelopper/rules/sdlc/app/Application.hpp>
#include <com/github/doevelopper/rules/sdlc/app/ApplicationPrivate.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::semver;


log4cxx::LoggerPtr Application::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.Application"));

Application::Application() noexcept
    // : d_ptr ( new ApplicationPrivate ( ) )
    : m_version()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Q_D(Application);
}

Application::Application(int & argc, char ** argv)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

Application::~Application() noexcept
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

int Application::start()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

// bool Application::initialize(int argc, char ** argv)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void Application::startup()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void Application::shutdown()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void Application::exec()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void Application::quit()
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// bool Application::is_quiting() const
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// void Application::register_config_type_comparison(std::type_index i, ConfigComparison comp)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
//     // Q_D ( Application );

//     // d_ptr->_any_compare_map.emplace(i, comp);
// }
