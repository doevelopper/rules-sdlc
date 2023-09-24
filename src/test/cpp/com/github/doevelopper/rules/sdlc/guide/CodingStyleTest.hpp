#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_GUIDE_CODINGSTYLETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_GUIDE_CODINGSTYLETEST_HPP

#include <com/github/doevelopper/rules/sdlc/CodingStyle.hpp>
#include <string>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::guide::test
{
    class CodingStyleTest : public ::testing::Test
    {
        // LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        CodingStyleTest();
        CodingStyleTest(const CodingStyleTest &)             = delete;
        CodingStyleTest(CodingStyleTest &&)                  = delete;
        CodingStyleTest & operator=(const CodingStyleTest &) = delete;
        CodingStyleTest & operator=(CodingStyleTest &&)      = delete;
        virtual ~CodingStyleTest();

        void SetUp() override;
        void TearDown() override;

    protected:
    private:

        com::github::doevelopper::rules::sdlc::guide::CodingStyle * m_targetUnderTest;
    };
}
#endif
