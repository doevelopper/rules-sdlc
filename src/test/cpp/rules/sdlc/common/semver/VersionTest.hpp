

#ifndef RULES_SDLC_STD_SEMVER_VERSIONTEST_HPP
#define RULES_SDLC_STD_SEMVER_VERSIONTEST_HPP

#include <rules/sdlc/common/semver/Version.hpp>
#include <rules/sdlc/common/UnitTest.hpp>

namespace rules::sdlc::stdc::semver::test
{

    class VersionTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:
        VersionTest();
        VersionTest(const VersionTest &) = delete;
        VersionTest(VersionTest &&) = delete;
        VersionTest & operator=(const VersionTest &) = delete;
        VersionTest & operator=(VersionTest &&) = delete;
        virtual ~VersionTest();

        void SetUp() override;
        void TearDown() override;

    protected:
        rules::sdlc::stdc::semver::Version * testee;

    private:
    };
}
#endif
