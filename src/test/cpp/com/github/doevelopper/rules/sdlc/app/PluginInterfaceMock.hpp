#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_PLUGININTERFACEMOCK_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_PLUGININTERFACEMOCK_HPP
#include <com/github/doevelopper/rules/sdlc/app/PluginInterface.hpp>

#include <gmock/gmock.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class PluginInterfaceMock: public ::testing::NiceMock<PluginInterface>
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:
        PluginInterfaceMock();
        PluginInterfaceMock(const PluginInterfaceMock &)             = delete;
        PluginInterfaceMock(PluginInterfaceMock &&)                  = delete;
        PluginInterfaceMock & operator=(const PluginInterfaceMock &) = delete;
        PluginInterfaceMock & operator=(PluginInterfaceMock &&)      = delete;
        virtual ~PluginInterfaceMock();


        MOCK_METHOD(State, state, (), (const, override));
        MOCK_METHOD(const std::string &, name, (), (const, override));
        MOCK_METHOD(void, programOptions,(OptionDesc & cli, OptionDesc & cfg), (override));
        MOCK_METHOD(void, initialize, (const OptionMap& options), (override));
        MOCK_METHOD(void, handleSignalHangUp, (), (override));
        MOCK_METHOD(void, startup, (), (override));
        MOCK_METHOD(void, shutdown, (), (override));

    protected:

    private:

    };
}
#endif
