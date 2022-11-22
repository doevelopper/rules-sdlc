

#include <rules/sdlc/std/semver/VersionTest.hpp>

using namespace rules::sdlc::stdc::semver;
using namespace rules::sdlc::stdc::semver::test;

log4cxx::LoggerPtr VersionTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.semver.test.VersionTest"));

VersionTest::VersionTest()
    :  testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionTest::~VersionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if(testee)
        delete testee;
    testee = nullptr;
}

void VersionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    testee = new Version();
}

void VersionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(VersionTest, Test_VersionTest_Default_Construction)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    Version v(std::string("0.0.0"));
    EXPECT_FALSE(testee->isEquals(v));
    EXPECT_FALSE(testee->isOlderThen(v));
    EXPECT_TRUE(testee->isNewerThen(v));

}

TEST_F(VersionTest, Test_VersionTest_Default_Version)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    EXPECT_EQ(testee->getMajor(),0);
    EXPECT_EQ(testee->getMinor(),0);
    EXPECT_EQ(testee->getPatch(),1);
    EXPECT_EQ(testee->getBuild(),std::string());
    EXPECT_NE(testee->maturity(),std::string());
    // Version v(std::string("0.0.2"));
    // EXPECT_EQ(testee->compareVersion(v),1);
}

// TEST_F(VersionTest, Test_VersionTest_Parsing)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// TEST_F(VersionTest, Test_VersionTest_Compare)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// TEST_F(VersionTest, Test_VersionTest_Invalid)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// TEST_F(VersionTest, Test_VersionTest_Parse_Prerelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// TEST_F(VersionTest, Test_VersionTest_Invalid_Prerelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }

// TEST_F(VersionTest, Test_VersionTest_Compare_Prerelease)
// {
//     LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
// }
