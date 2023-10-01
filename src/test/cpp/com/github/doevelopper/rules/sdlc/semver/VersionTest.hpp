
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_GITREVISIONTEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_SEMVER_GITREVISIONTEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/Version.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::semver::test
{
    template <typename V>
    class VersionTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        VersionTest();
        VersionTest(const VersionTest &)             = delete;
        VersionTest(VersionTest &&)                  = delete;
        VersionTest & operator=(const VersionTest &) = delete;
        VersionTest & operator=(VersionTest &&)      = delete;
        virtual ~VersionTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::semver::Version<V> * m_targetUnderTest;

    private:
    };

    TYPED_TEST_SUITE_P(VersionTest);
}
#endif
