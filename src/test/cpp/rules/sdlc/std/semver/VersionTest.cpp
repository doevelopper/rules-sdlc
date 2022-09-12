
#include<rules/sdlc/std/semver/VersionTest.hpp>

using namespace rules::sdlc::stdc::semver;
using namespace rules::sdlc::stdc::semver::test;

log4cxx::LoggerPtr VersionTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.test.VersionTest"));

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

TEST_F(VersionTest, test_Version_default_constructor)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // EXPECT_EQ(0,testee->major());
    // EXPECT_EQ(0,testee->minor());
    // EXPECT_EQ(0,testee->patch());
}

TEST_F(VersionTest, test_Version_invalid)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    Version v("-1.0.0");
    // EXPECT_EQ(0,testee->major());
    // EXPECT_EQ(0,testee->minor());
    // EXPECT_EQ(0,testee->patch());
}

TEST_F(VersionTest, test_Version_valid)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    Version v("1.0.0");
    // EXPECT_EQ(0,testee->major());
    // EXPECT_EQ(0,testee->minor());
    // EXPECT_EQ(0,testee->patch());
}

TEST_F(VersionTest, test_Version_string)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    Version v("1.0.0");
    // EXPECT_EQ(0,testee->major());
    // EXPECT_EQ(0,testee->minor());
    // EXPECT_EQ(0,testee->patch());
}
