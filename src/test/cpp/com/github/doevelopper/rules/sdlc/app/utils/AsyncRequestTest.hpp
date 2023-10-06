
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNCREQUESTTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNCREQUESTTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncRequest.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::utils::test
{
    template <typename V>
    class AsyncRequestTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        AsyncRequestTest();
        AsyncRequestTest(const AsyncRequestTest &)             = delete;
        AsyncRequestTest(AsyncRequestTest &&)                  = delete;
        AsyncRequestTest & operator=(const AsyncRequestTest &) = delete;
        AsyncRequestTest & operator=(AsyncRequestTest &&)      = delete;
        virtual ~AsyncRequestTest();

        //  (:)
        AsyncRequest<V> requestInteger();
        //  (:)
        AsyncRequest<V> requestDelayedInteger();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::utils::AsyncRequest<V> * m_targetUnderTest;

    private:
    };

    TYPED_TEST_SUITE_P(AsyncRequestTest);
}
#endif
