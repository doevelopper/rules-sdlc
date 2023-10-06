
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_MESSAGEQUEUETEST_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_MESSAGEQUEUETEST_HPP

#include <com/github/doevelopper/rules/sdlc/app/utils/MessageQueue.hpp>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::app::utils::test
{
    using ParameterValueTypes = ::testing::Types<bool, char, int, unsigned int, float, double>;

    template <typename V>
    class MessageQueueTest : public ::testing::Test
    {
        LOG4CXX_DECLARE_STATIC_TEST_LOGGER
    public:

        MessageQueueTest();
        MessageQueueTest(const MessageQueueTest &)             = delete;
        MessageQueueTest(MessageQueueTest &&)                  = delete;
        MessageQueueTest & operator=(const MessageQueueTest &) = delete;
        MessageQueueTest & operator=(MessageQueueTest &&)      = delete;
        virtual ~MessageQueueTest();

        void SetUp() override;
        void TearDown() override;

    protected:

        com::github::doevelopper::rules::sdlc::app::utils::MessageQueue<V> * m_targetUnderTest;
        // using testee    = com::github::doevelopper::rules::sdlc::app::utils::MessageQueue<v>;
        // using ValueType = V;
        size_t max_size;

    private:
    };

    TYPED_TEST_SUITE_P(MessageQueueTest);
}
#endif
