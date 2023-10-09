
#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncPromise.hpp>
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncRequestTest.hpp>
#include <com/github/doevelopper/rules/sdlc/app/utils/AsyncTask.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::utils;
using namespace com::github::doevelopper::rules::sdlc::app::utils::test;

template <typename V>
log4cxx::LoggerPtr AsyncRequestTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.AsyncRequestTest"));

template <typename V>
AsyncRequestTest<V>::AsyncRequestTest()
    : m_targetUnderTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
AsyncRequestTest<V>::~AsyncRequestTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void AsyncRequestTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new AsyncRequest<V>();
}

template <typename V>
void AsyncRequestTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

// //  (:)
template <typename V>
AsyncRequest<V> AsyncRequestTest<V>::requestInteger()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return AsyncTask<int>([]() {
        int v = 0;
        for (int i = 0; i < 123; ++i)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            v += 1;
        }
        return v;
    });
}

//  (:)
template <typename V>
AsyncRequest<V> AsyncRequestTest<V>::requestDelayedInteger()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    AsyncPromise<V> promise;
    AsyncRequest<V> request = promise.get_request();

    std::jthread thread([promise = std::move(promise)]() mutable {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        promise.set_result(123);
    });
    thread.detach();

    return request;
}

TYPED_TEST_P(AsyncRequestTest, Test_Destruction)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    //     // {
    //     //     AsyncTask<int> request([](std::stop_token sstoken) {
    //     //         while (!sstoken.stop_requested())
    //     //         {
    //     //             // endless loop
    //     //             std::this_thread::yield();
    //     //         }
    //     //         return 0;
    //     //     });
    //     // }
    //     // SUCCEED();
}

TYPED_TEST_P(AsyncRequestTest, Test_Move)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncRequest<int> request = requestInteger();
    // EXPECT_EQ(request.await(), 123);
}

TYPED_TEST_P(AsyncRequestTest, Test_Void_Request)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    //     AsyncTask<void> request([]() {
    //         std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //         // do nothing
    //     });
    //     EXPECT_NO_THROW(request.await());
}

TYPED_TEST_P(AsyncRequestTest, Test_Await)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncTask<int> request([]() {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //     return 123;
    // });

    // EXPECT_EQ(request.await(), 123);
    // EXPECT_THROW(request.await(), std::future_error);
}

TYPED_TEST_P(AsyncRequestTest, Test_Is_Ready)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncTask<int> request([]() {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //     return 123;
    // });

    // EXPECT_FALSE(request.is_ready());
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    // EXPECT_TRUE(request.is_ready());
    // EXPECT_EQ(request.await(), 123);
}

TYPED_TEST_P(AsyncRequestTest, Test_Request_Stop)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // std::atomic_bool never_true = false;
    // AsyncTask<int> request([&](std::stop_token sstoken) {
    //     std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //     while (!sstoken.stop_requested())
    //     {
    //         never_true = true;
    //     }
    //     return 0;
    // });

    // request.cancel();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    // EXPECT_FALSE(never_true);
}

TYPED_TEST_P(AsyncRequestTest, Test_Delayed_Creation)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncRequest<int> request = requestDelayedInteger();
    // EXPECT_EQ(request.await(), 123);
}

TYPED_TEST_P(AsyncRequestTest, Test_Then)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncRequest<int> request = requestInteger();
    // request.then([](int value) { EXPECT_EQ(value, 123); });
    // request.wait();
}

TYPED_TEST_P(AsyncRequestTest, Test_Then_Sstoken)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncRequest<int> request = requestInteger();
    // request.then([](std::stop_token sstoken, int value) { EXPECT_EQ(value, 123); });
    // request.wait();
}

TYPED_TEST_P(AsyncRequestTest, Test_Then_Cancel)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    // AsyncRequest<int> request = requestInteger();
    // request.then([](std::stop_token sstoken, int value) { FAIL() << "should never be reached"; });
    // request.cancel();
}

TYPED_TEST_P(AsyncRequestTest, Test_Request_With_Exception)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    //     // AsyncTask<void> request([]() {
    //     //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     //     throw std::runtime_error("expected failure");
    //     // });

    //     // EXPECT_THROW(request.await(), std::runtime_error);
}

TYPED_TEST_P(AsyncRequestTest, Test_Request_With_Exception_Cancel)
{
    LOG4CXX_TRACE(TestFixture::logger, __LOG4CXX_FUNC__);
    //     // AsyncTask<void> request([]() {
    //     //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     //     throw std::runtime_error("expected failure");
    //     // });

    //     // EXPECT_NO_THROW(request.wait());
}

REGISTER_TYPED_TEST_SUITE_P(
    AsyncRequestTest, Test_Destruction, Test_Move, Test_Void_Request, Test_Await, Test_Is_Ready, Test_Request_Stop,
    Test_Delayed_Creation, Test_Then, Test_Then_Sstoken, Test_Then_Cancel, Test_Request_With_Exception,
    Test_Request_With_Exception_Cancel);

INSTANTIATE_TYPED_TEST_SUITE_P(TestOfAsyncRequest, AsyncRequestTest, NoOp);
