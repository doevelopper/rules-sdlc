
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_PLUGININTERFACETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_PLUGININTERFACETEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/PluginInterfaceMock.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class PluginInterfaceTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        PluginInterfaceTest();
        PluginInterfaceTest(const PluginInterfaceTest &)             = delete;
        PluginInterfaceTest(PluginInterfaceTest &&)                  = delete;
        PluginInterfaceTest & operator=(const PluginInterfaceTest &) = delete;
        PluginInterfaceTest & operator=(PluginInterfaceTest &&)      = delete;
        virtual ~PluginInterfaceTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::test::PluginInterfaceMock * m_targetUnderTest;

    private:
    };
}
#endif
