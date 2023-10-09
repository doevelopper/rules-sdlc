
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNCTASKTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_ASYNCTASKTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncTask.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::utils::test
{
    template <typename V>
    class AsyncTaskTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        AsyncTaskTest();
        AsyncTaskTest(const AsyncTaskTest &)             = delete;
        AsyncTaskTest(AsyncTaskTest &&)                  = delete;
        AsyncTaskTest & operator=(const AsyncTaskTest &) = delete;
        AsyncTaskTest & operator=(AsyncTaskTest &&)      = delete;
        virtual ~AsyncTaskTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::utils::AsyncTask<V> * m_targetUnderTest;
        V ValueType;

    private:
    };

    using FundamentalTypes = ::testing::Types<
        char, unsigned char, wchar_t, short int, unsigned short int, int, unsigned int, long int, unsigned long int,
        long long int, unsigned long long int, float, double, long double>;
    using NoOpTypes = ::testing::Types<com::github::doevelopper::rules::sdlc::app::NoOp>;
    TYPED_TEST_SUITE_P(AsyncTaskTest);
}
#endif
