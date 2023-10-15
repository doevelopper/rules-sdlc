
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLERTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLERTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/QueuedHandler.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    template <typename V>
    class QueuedHandlerTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        QueuedHandlerTest();
        QueuedHandlerTest(const QueuedHandlerTest &)             = delete;
        QueuedHandlerTest(QueuedHandlerTest &&)                  = delete;
        QueuedHandlerTest & operator=(const QueuedHandlerTest &) = delete;
        QueuedHandlerTest & operator=(QueuedHandlerTest &&)      = delete;
        virtual ~QueuedHandlerTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        // com::github::doevelopper::rules::sdlc::app::QueuedHandler<V> * m_targetUnderTest;

    private:
    };
    TYPED_TEST_SUITE_P(QueuedHandlerTest);
}
#endif
