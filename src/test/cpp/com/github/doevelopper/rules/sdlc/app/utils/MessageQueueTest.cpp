
#include <thread>

#include <com/github/doevelopper/rules/sdlc/app/NoOp.hpp>
#include <com/github/doevelopper/rules/sdlc/app/utils/MessageQueueTest.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;
using namespace com::github::doevelopper::rules::sdlc::app::utils;
using namespace com::github::doevelopper::rules::sdlc::app::utils::test;

template <typename V>
log4cxx::LoggerPtr MessageQueueTest<V>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.test.MessageQueueTest"));

template <typename V>
MessageQueueTest<V>::MessageQueueTest()
    : m_targetUnderTest()
    , max_size(5)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
MessageQueueTest<V>::~MessageQueueTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename V>
void MessageQueueTest<V>::SetUp()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    // m_targetUnderTest = new MessageQueue<V>(max_size);
}

template <typename V>
void MessageQueueTest<V>::TearDown()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // if (this->m_targetUnderTest)
    //     delete m_targetUnderTest;
    // this->m_targetUnderTest = nullptr;
}

TYPED_TEST_P(MessageQueueTest, Test_push_pop)
{
    //     // LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    //     // MessageQueue<int> queue;
    //     // EXPECT_TRUE(queue.try_push(1));
    //     // EXPECT_TRUE(queue.try_push(2));
    //     // EXPECT_TRUE(queue.try_push(3));
    //     // EXPECT_TRUE(queue.try_push(4));

    //     // EXPECT_EQ(queue.size(), 4);

    //     // int value;
    //     // EXPECT_EQ((queue.try_pop(value), value), 1);
    //     // EXPECT_EQ((queue.try_pop(value), value), 2);
    //     // EXPECT_EQ((queue.try_pop(value), value), 3);
    //     // EXPECT_EQ((queue.try_pop(value), value), 4);
}

TYPED_TEST_P(MessageQueueTest, Test_push_pop_limit)
{
    //     // MessageQueue<int> queue(3);

    //     // EXPECT_TRUE(queue.try_push(1));
    //     // EXPECT_FALSE(queue.full());
    //     // EXPECT_TRUE(queue.try_push(2));
    //     // EXPECT_FALSE(queue.full());
    //     // EXPECT_TRUE(queue.try_push(3));
    //     // EXPECT_TRUE(queue.full());
    //     // EXPECT_FALSE(queue.try_push(4));
    //     // EXPECT_TRUE(queue.full());

    //     // EXPECT_EQ(queue.size(), 3);

    //     // int value;
    //     // EXPECT_EQ((queue.try_pop(value), value), 1);
    //     // EXPECT_EQ((queue.try_pop(value), value), 2);
    //     // EXPECT_EQ((queue.try_pop(value), value), 3);
    //     // EXPECT_FALSE(queue.try_pop(value));
}

TYPED_TEST_P(MessageQueueTest, Test_wait_and_pushpop)
{
    //     // MessageQueue<int> queue(3);

    //     // std::jthread thread([&] {
    //     //     for (int i = 0; i < 10; ++i)
    //     //     {
    //     //         std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     //         queue.wait_and_push(i, thread.get_stop_token());
    //     //     }
    //     // });

    //     // for (int i = 0; i < 10; ++i)
    //     // {
    //     //     int value;
    //     //     queue.wait_and_pop(value, thread.get_stop_token());
    //     //     EXPECT_EQ(i, value);
    //     // }
}

TYPED_TEST_P(MessageQueueTest, Test_wait_and_push_interruption)
{
    //     //     MessageQueue<int> queue(3);

    //     //     std::jthread thread([&](std::stop_token stoken) {
    //     //         for (int i = 0; i < 10; ++i)
    //     //         {
    //     //             std::this_thread::sleep_for(std::chrono::milliseconds(5));
    //     //             queue.wait_and_push(i, stoken);
    //     //         }
    //     //     });
    //     //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

TYPED_TEST_P(MessageQueueTest, Test_wait_and_pop_interruption)
{
    // //     // MessageQueue<int> queue(3);

    // //     // std::jthread thread([&](std::stop_token stoken) {
    // //     //     int value;
    // //     //     queue.wait_and_pop(value, stoken);
    // //     // });
    // //     // std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

REGISTER_TYPED_TEST_SUITE_P(
    MessageQueueTest, Test_push_pop, Test_push_pop_limit, Test_wait_and_pushpop, Test_wait_and_push_interruption,
    Test_wait_and_pop_interruption);

INSTANTIATE_TYPED_TEST_SUITE_P(TestOfMessageQueue, MessageQueueTest, NoOp);
