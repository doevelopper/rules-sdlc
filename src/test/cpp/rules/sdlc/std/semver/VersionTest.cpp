

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
    EXPECT_EQ(testee->to_string(), "0.0.1-SNAPSHOOT");
    EXPECT_TRUE(testee);//operator bool ( )
    // Version versions(std::string("0.0.0"));
}
