

#include<rules/sdlc/std/DummyTest.hpp>

using namespace rules::sdlc::stdc;
using namespace rules::sdlc::stdc::test;

log4cxx::LoggerPtr DummyTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.test.DummyTest"));

DummyTest::DummyTest()
    :  testee()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

DummyTest::~DummyTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    if(testee)
        delete testee;
    testee = nullptr;
}

void DummyTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
    testee = new Dummy();
}

void DummyTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__ );
}

TEST_F(DummyTest, test_Simple)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // EXPECT_TRUE(testee->speechless());
    // EXPECT_TRUE(testee->speak().compare("Hi"));
    // EXPECT_TRUE(testee->isValid());
}
