
#include <com/github/doevelopper/rules/sdlc/extensions/UnitTestBuilder.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/VersionTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::semver;
using namespace com::github::doevelopper::rules::sdlc::semver::test;

log4cxx::LoggerPtr VersionTest::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.semver.test.VersionTest"));

VersionTest::VersionTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

VersionTest::~VersionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void VersionTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Version<???>();
}

void VersionTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TEST_F(VersionTest, Test_Not_Yet_Implemented)
{
    // UnitTestBuilder::notYetImplemented();
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
