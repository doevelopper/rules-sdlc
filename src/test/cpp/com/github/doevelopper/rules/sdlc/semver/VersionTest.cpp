
#include <com/github/doevelopper/rules/sdlc/extensions/UnitTestBuilder.hpp>
#include <com/github/doevelopper/rules/sdlc/semver/VersionTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::semver;
using namespace com::github::doevelopper::rules::sdlc::semver::test;

template <typename V>
log4cxx::LoggerPtr VersionTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.semver.test.VersionTest"));

template <typename V>
VersionTest<V>::VersionTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
VersionTest<V>::~VersionTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void VersionTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Version<V>();
}

template <typename V>
void VersionTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_targetUnderTest)
        delete m_targetUnderTest;
    this->m_targetUnderTest = nullptr;
}

TYPED_TEST_P(VersionTest, Test_Not_Yet_Implemented)
{
    // UnitTestBuilder::notYetImplemented();
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

REGISTER_TYPED_TEST_SUITE_P(VersionTest, Test_Not_Yet_Implemented);

INSTANTIATE_TYPED_TEST_SUITE_P(TestVersion, VersionTest, com::github::doevelopper::rules::sdlc::app::NoOp);
