
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORELOCKTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORELOCKTEST_HPP

#include <thread>

#include <com/github/doevelopper/rules/sdlc/app/utils/SemaphoreLock.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::utils::test
{
    class SemaphoreLockTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        SemaphoreLockTest();
        SemaphoreLockTest(const SemaphoreLockTest &)             = delete;
        SemaphoreLockTest(SemaphoreLockTest &&)                  = delete;
        SemaphoreLockTest & operator=(const SemaphoreLockTest &) = delete;
        SemaphoreLockTest & operator=(SemaphoreLockTest &&)      = delete;
        virtual ~SemaphoreLockTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::utils::SemaphoreLock * m_targetUnderTest;

    private:
    };
}
#endif
