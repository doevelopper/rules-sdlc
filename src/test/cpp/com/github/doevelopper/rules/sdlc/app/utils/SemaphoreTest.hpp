
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_SEMAPHORETEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/Semaphore.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::utils::test
{
    class SemaphoreTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        SemaphoreTest();
        SemaphoreTest(const SemaphoreTest &)             = delete;
        SemaphoreTest(SemaphoreTest &&)                  = delete;
        SemaphoreTest & operator=(const SemaphoreTest &) = delete;
        SemaphoreTest & operator=(SemaphoreTest &&)      = delete;
        virtual ~SemaphoreTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::utils::Semaphore * m_targetUnderTest;

    private:
    };
}
#endif
