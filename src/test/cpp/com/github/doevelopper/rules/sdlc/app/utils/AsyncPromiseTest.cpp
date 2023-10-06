
#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>

#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncPromiseTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::utils;
using namespace com::github::doevelopper::rules::sdlc::app::utils::test;

template <typename V>
log4cxx::LoggerPtr AsyncPromiseTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.AsyncPromiseTest"));

template <typename V>
AsyncPromiseTest<V>::AsyncPromiseTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
AsyncPromiseTest<V>::~AsyncPromiseTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void AsyncPromiseTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new Application();
}

template <typename V>
void AsyncPromiseTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TYPED_TEST_P(AsyncPromiseTest, Test_Not_Yet_Implemented)
{
    // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // AsyncPromise<int> promise;
    // AsyncRequest<int> request = promise.get_request();
}

REGISTER_TYPED_TEST_SUITE_P(AsyncPromiseTest, Test_Not_Yet_Implemented);

INSTANTIATE_TYPED_TEST_SUITE_P(TestOfAsyncPromiseTest, AsyncPromiseTest, NoOp);
