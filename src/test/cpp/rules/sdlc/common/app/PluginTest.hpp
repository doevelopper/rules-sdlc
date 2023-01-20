
#ifndef RULES_SDLC_STD_APP_PLUGINTEST_HPP
#define RULES_SDLC_STD_APP_PLUGINTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/common/app/Plugin.hpp>

namespace rules::sdlc::stdc::app::test
{

    class PluginTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:
        PluginTest();
        virtual ~PluginTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:
        // rules::sdlc::stdc::app::Application * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(PluginTest)
    };
}
#endif
