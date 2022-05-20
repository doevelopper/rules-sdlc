
#ifndef RULES_SDLC_STD_APP_CHANNELTEST_HPP
#define RULES_SDLC_STD_APP_CHANNELTEST_HPP

#include <gtest/gtest.h>
#include <rules/sdlc/std/app/Channel.hpp>

namespace rules::sdlc::stdc::app::test
{

    class ChannelTest : public ::testing::Test
    {
    LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:

        ChannelTest();
        virtual ~ChannelTest();

        void SetUp() override;
        void TearDown() override;

    protected:

    private:

        // rules::sdlc::stdc::app::Channel * m_targetUnderTest;
        Q_DISABLE_COPY_MOVE(ChannelTest)
    };
}
#endif
