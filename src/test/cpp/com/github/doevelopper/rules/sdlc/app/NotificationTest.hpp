
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_NOTIFICATIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_NOTIFICATIONTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/Notification.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    using ParameterValueTypes = ::testing::Types<bool, char, int, unsigned int, float, double>;

    template <typename V>
    class NotificationTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        NotificationTest();
        NotificationTest(const NotificationTest &)             = delete;
        NotificationTest(NotificationTest &&)                  = delete;
        NotificationTest & operator=(const NotificationTest &) = delete;
        NotificationTest & operator=(NotificationTest &&)      = delete;
        virtual ~NotificationTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        // com::github::doevelopper::rules::sdlc::app::Notification * m_targetUnderTest;
        // ::testing::MockFunction notification;
        using  testee = com::github::doevelopper::rules::sdlc::app::Notification<V>;
        using  ValueType = V;
    private:
    };

    TYPED_TEST_SUITE_P(NotificationTest);
}
#endif
