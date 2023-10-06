
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNCPROMISETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNCPROMISETEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncPromise.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::utils::test
{
    template <typename V>
    class AsyncPromiseTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        AsyncPromiseTest();
        AsyncPromiseTest(const AsyncPromiseTest &)             = delete;
        AsyncPromiseTest(AsyncPromiseTest &&)                  = delete;
        AsyncPromiseTest & operator=(const AsyncPromiseTest &) = delete;
        AsyncPromiseTest & operator=(AsyncPromiseTest &&)      = delete;
        virtual ~AsyncPromiseTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::utils::AsyncPromise<V> * m_targetUnderTest;

    private:
    };

    TYPED_TEST_SUITE_P(AsyncPromiseTest);
}
#endif
