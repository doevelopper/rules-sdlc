

#include <com/github/doevelopper/rules/sdlc/app/Application.hpp>
#include <com/github/doevelopper/rules/sdlc/app/ApplicationPrivate.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::semver;

log4cxx::LoggerPtr Application::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.ApplicationPrivate"));

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

bool Application::initialize(int argc, char ** argv)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename T>
void Application::registerConfigType(T type)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    registerConfigTypeComparison(typeid(T), [](const auto & a, const auto & b) {
        return boost::any_cast<const T &>(a) == boost::any_cast<const T &>(b);
    });
}

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

void Application::registerConfigTypeComparison(std::type_index i, ConfigComparison comp)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // Q_D ( Application );

    // d_ptr->_any_compare_map.emplace(i, comp);
}

PluginInterface * Application::findPlugin(const std::string & name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

PluginInterface & Application::getPlugin(const std::string & name) const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename Plugin>
Plugin & Application::getPlugin() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename Plugin>
Plugin * Application::findPlugin() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
