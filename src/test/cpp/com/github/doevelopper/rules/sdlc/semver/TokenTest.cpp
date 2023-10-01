#include <com/github/doevelopper/rules/sdlc/semver/TokenTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::semver;
using namespace com::github::doevelopper::rules::sdlc::semver::test;

log4cxx::LoggerPtr TokenTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.semver.test.TokenTest"));

TokenTest::TokenTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TokenTest::~TokenTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void TokenTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new Token();
}

void TokenTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(TokenTest, Test_Not_Yet_Implemented)
{
    // UnitTestBuilder::notYetImplemented();
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
