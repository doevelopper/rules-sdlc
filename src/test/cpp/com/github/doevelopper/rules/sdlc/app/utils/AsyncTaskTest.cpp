
#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>

#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncTaskTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::utils;
using namespace com::github::doevelopper::rules::sdlc::app::utils::test;

template <typename V>
log4cxx::LoggerPtr AsyncTaskTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.AsyncTaskTest"));

template <typename V>
AsyncTaskTest<V>::AsyncTaskTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
AsyncTaskTest<V>::~AsyncTaskTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void AsyncTaskTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Application(); get<0>(GetParam())
}

template <typename V>
void AsyncTaskTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TYPED_TEST_P(AsyncTaskTest, Test_Not_Yet_Implemented)
{
    // LOG4CXX_TRACE(AsyncTaskTest<ValueType>::logger, __LOG4CXX_FUNC__);
    // TypeParam n = this->ValueType;
}

REGISTER_TYPED_TEST_SUITE_P(AsyncTaskTest, Test_Not_Yet_Implemented);

INSTANTIATE_TYPED_TEST_SUITE_P(TestOfAsyncTaskTest, AsyncTaskTest, NoOp);
