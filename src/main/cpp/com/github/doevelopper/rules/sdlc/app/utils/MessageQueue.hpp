
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_MESSAGEQUEUE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_APP_UTILS_MESSAGEQUEUE_HPP

#include <assert.h>
#include <condition_variable>
#include <functional>
#include <limits>
#include <mutex>
#include <queue>

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

namespace com::github::doevelopper::rules::sdlc::app::utils
{
    template <typename Data>
    class MessageQueue
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        MessageQueue() = delete;
        explicit MessageQueue(size_t max_size = std::numeric_limits<size_t>::max());
        ~MessageQueue() noexcept;
        bool full() const;
        size_t size() const;
        bool empty() const;
        /** Try to push data on the queue, if the queue is full, fail and return false */
        bool try_push(const Data & data);
        /** Try pop data from the queue, if it's empty return false */
        bool try_pop(Data & data_out);
        /** Push data on the queue, if the queue is currently full, wait till it is no longer full */
        void wait_and_push(const Data & data, std::stop_token stoken);
        /** Pop data from the queue, if it's empty, wait till data is available */
        void wait_and_pop(Data & data_out, std::stop_token stoken);
        /** Waits till the queue is ready to accept a push */
        void wait_for_push(std::stop_token stoken);
        /** wait till the queue allows a pop */
        void wait_for_pop(std::stop_token stoken);

    protected:
    private:

        MessageQueue(const MessageQueue &);
        MessageQueue & operator=(const MessageQueue &);

        std::queue<Data> m_queue;
        size_t m_max_size;
        mutable std::mutex m_mutex;
        std::condition_variable_any m_queue_not_empty_cond;
        std::condition_variable_any m_queue_not_full_cond;
    };
}

#endif
