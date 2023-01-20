
#include <project/object/model/DummyPlugin.hpp>

using namespace rules::sdlc::stdc;

log4cxx::LoggerPtr DummyPlugin::logger = log4cxx::Logger::getLogger(std::string("project.object.model.DummyPlugin"));

DummyPlugin::DummyPlugin()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

DummyPlugin::~DummyPlugin()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
/*
State DummyPlugin::state() const override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

const std::string & DummyPlugin::name() const override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void DummyPlugin::initialize(const OptionMap & options) override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void DummyPlugin::handleSignalHangUp() override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void DummyPlugin::startup() override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void DummyPlugin::shutdown() override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void DummyPlugin::registerPlugings() override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

void DummyPlugin::options( OptionDesc & cli, OptionDesc & cfg ) override
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}
*/
