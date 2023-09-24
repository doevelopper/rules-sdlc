#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_GUIDE_DUMMYTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_GUIDE_DUMMYTEST_HPP

#include <com/github/doevelopper/rules/sdlc/guide/Dummy.hpp>
#include <string>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::guide::test
{
    class DummyTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        DummyTest();
        DummyTest(const DummyTest &)             = delete;
        DummyTest(DummyTest &&)                  = delete;
        DummyTest & operator=(const DummyTest &) = delete;
        DummyTest & operator=(DummyTest &&)      = delete;
        virtual ~DummyTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::guide::Dummy * m_targetUnderTest;

    private:
    };
}

#endif
