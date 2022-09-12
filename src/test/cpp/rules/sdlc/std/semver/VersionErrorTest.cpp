#include<rules/sdlc/std/semver/VersionErrorTest.hpp>

using namespace rules::sdlc::stdc::semver;
using namespace rules::sdlc::stdc::semver::test;

log4cxx::LoggerPtr VersionErrorTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.test.VersionErrorTest"));

VersionErrorTest::VersionErrorTest()
    :  testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

VersionErrorTest::~VersionErrorTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if(testee)
        delete testee;
    testee = nullptr;
}

void VersionErrorTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    testee = new VersionError();
}

void VersionErrorTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(VersionErrorTest, Test_Not_Yet_Implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
