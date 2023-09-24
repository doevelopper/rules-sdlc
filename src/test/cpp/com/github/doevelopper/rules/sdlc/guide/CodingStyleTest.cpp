#include <com/github/doevelopper/rules/sdlc/CodingStyleTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::guide;
using namespace com::github::doevelopper::rules::sdlc::guide::test;

CodingStyleTest::CodingStyleTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

CodingStyleTest::~CodingStyleTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

void CodingStyleTest::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_targetUnderTest = new OptionDescription();
}

void CodingStyleTest::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete m_targetUnderTest;
}

TEST_F(CodingStyleTest, test_not_yedt_implemented)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}
