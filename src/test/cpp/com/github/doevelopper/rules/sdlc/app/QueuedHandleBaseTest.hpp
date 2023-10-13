
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLEBASETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_QUEUEDHANDLEBASETEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/QueuedHandleBase.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::test
{
    class QueuedHandleBaseTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        QueuedHandleBaseTest();
        QueuedHandleBaseTest(const QueuedHandleBaseTest &)             = delete;
        QueuedHandleBaseTest(QueuedHandleBaseTest &&)                  = delete;
        QueuedHandleBaseTest & operator=(const QueuedHandleBaseTest &) = delete;
        QueuedHandleBaseTest & operator=(QueuedHandleBaseTest &&)      = delete;
        virtual ~QueuedHandleBaseTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::QueuedHandleBase * m_targetUnderTest;

    private:
    };
}
#endif
