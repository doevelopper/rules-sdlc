
#include <boost/core/demangle.hpp>
#include <rules/sdlc/common/app/Plugin.hpp>

using namespace rules::sdlc::stdc::app;

template <typename I>
log4cxx::LoggerPtr Plugin<I>::logger = log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.app.Plugin"));

template <typename I>
Plugin<I>::Plugin()
    : m_pluginName(std::string(boost::core::demangle(typeid(I).name())))
    , m_pluginState(PluginInterface::State::DISABLED)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename I>
Plugin<I>::Plugin(const std::string & name)
    : m_pluginName(name)
    , m_pluginState(PluginInterface::State::DISABLED)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename I>
Plugin<I>::~Plugin()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename I>
PluginInterface::State Plugin<I>::state() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (m_pluginState);
}

template <typename I>
const std::string & Plugin<I>::name() const
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (m_pluginName);
}

template <typename I>
void Plugin<I>::options(OptionDesc & cli, OptionDesc & cfg)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename I>
void Plugin<I>::initialize(const OptionMap & options)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_pluginState == State::REGISTERED)
    {
        m_pluginState = State::INITIALIZED;
        static_cast<I *>(this)->pluginRequires([&](auto & plugin) { plugin.initialize(options); });
        static_cast<I *>(this)->pluginRequires(options);

        // application().plugin_initialized(*this);
    }

    LOG4CXX_ASSERT(logger, m_pluginState == State::INITIALIZED, "Initial state was not registered");
}

template <typename I>
void Plugin<I>::handleSignalHangUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_pluginState == State::INITIALIZED)
    {
        m_pluginState = State::STARTED;

        // static_cast<I*>(this)->pluginRequires([&](auto& plugin){
        //    plugin.initialize(options);
        //});

        ////static_cast<I*>(this)->pluginRequires(options);
    }
}

template <typename I>
void Plugin<I>::startup()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename I>
void Plugin<I>::shutdown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename I>
void Plugin<I>::registerPlugings()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    static_cast<I *>(this)->pluginRequires([&](auto & plugin) {});
}
