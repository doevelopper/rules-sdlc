
#ifndef RULES_SDLC_STD_SEMVER_VERSIONERRORTEST_HPP
#define RULES_SDLC_STD_SEMVER_VERSIONERRORTEST_HPP

#include <rules/sdlc/std/UnitTest.hpp>
#include <rules/sdlc/std/semver/VersionError.hpp>

namespace rules::sdlc::stdc::semver::test
{

    class VersionErrorTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER

    public:

        VersionErrorTest();
        VersionErrorTest(const VersionErrorTest&) = delete;
        VersionErrorTest(VersionErrorTest&&) = delete;
        VersionErrorTest& operator=(const VersionErrorTest&) = delete;
        VersionErrorTest& operator=(VersionErrorTest&&) = delete;
        virtual ~VersionErrorTest();

        void SetUp() override;
        void TearDown() override;

    protected:
        rules::sdlc::stdc::semver::VersionError * testee;
    private:

    };
}
#endif
