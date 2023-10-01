
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_TOKENTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_TOKENTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/Token.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::semver::test
{
    class TokenTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        TokenTest();
        TokenTest(const TokenTest &)             = delete;
        TokenTest(TokenTest &&)                  = delete;
        TokenTest & operator=(const TokenTest &) = delete;
        TokenTest & operator=(TokenTest &&)      = delete;
        virtual ~TokenTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::semver::Token * m_targetUnderTest;

    private:
    };
}
#endif
