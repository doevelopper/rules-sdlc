
#include <com/github/doevelopper/rules/sdlc/app/utils/MessageQueue.hpp>

using namespace com::github::doevelopper::rules::sdlc::app::utils;

template <typename Data>
log4cxx::LoggerPtr MessageQueue<Data>::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.utils.MessageQueue"));

template <typename Data>
MessageQueue<Data>::~MessageQueue()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (this->m_queue)
        delete m_queue;
    this->m_queue = nullptr;
}

template <typename Data>
MessageQueue<Data>::MessageQueue(size_t max_size)
    : m_queue()
    , m_max_size(max_size)
    , m_mutex()
    , m_queue_not_empty_cond()
    , m_queue_not_full_cond()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

template <typename Data>
bool MessageQueue<Data>::full() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_queue.size() == m_max_size;
}

template <typename Data>
size_t MessageQueue<Data>::size() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_queue.size();
}

template <typename Data>
bool MessageQueue<Data>::empty() const
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return m_queue.empty();
}

/** Try to push data on the queue, if the queue is full, fail and return false */
template <typename Data>
bool MessageQueue<Data>::try_push(const Data & data)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    if (m_queue.size() == m_max_size)
    {
        return false;
    }
    else
    {
        // push the data to the queue
        m_queue.push(data);

        // notify that the queue is no longer empty
        lock.unlock();
        m_queue_not_empty_cond.notify_one();

        return true;
    }
}

/** Try pop data from the queue, if it's empty return false */
template <typename Data>
bool MessageQueue<Data>::try_pop(Data & data_out)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    if (m_queue.empty())
    {
        return false;
    }
    else
    {
        // pop the data
        data_out = m_queue.front();
        m_queue.pop();

        // notify that the queue is no longer full
        lock.unlock();
        m_queue_not_full_cond.notify_one();

        return true;
    }
}

/** Push data on the queue, if the queue is currently full, wait
    till it is no longer full */
template <typename Data>
void MessageQueue<Data>::wait_and_push(const Data & data, std::stop_token stoken)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_queue_not_full_cond.wait(lock, stoken, [this] { return m_queue.size() != m_max_size; });

    // push the data to the queue
    m_queue.push(data);

    // notify that the queue is no longer empty
    lock.unlock();
    m_queue_not_empty_cond.notify_one();
}

/** Pop data from the queue, if it's empty, wait till data is available */
template <typename Data>
void MessageQueue<Data>::wait_and_pop(Data & data_out, std::stop_token stoken)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    m_queue_not_empty_cond.wait(lock, stoken, [this] { return !m_queue.empty(); });

    // pop the data
    data_out = m_queue.front();
    m_queue.pop();

    // notify that the queue is no longer full
    lock.unlock();
    m_queue_not_full_cond.notify_one();
}

/** Waits till the queue is ready to accept a push */
template <typename Data>
void MessageQueue<Data>::wait_for_push(std::stop_token stoken)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_queue_not_full_cond.wait(lock, stoken, [this] { return m_queue.size() != m_max_size; });
}

/** wait till the queue allows a pop */
template <typename Data>
void MessageQueue<Data>::wait_for_pop(std::stop_token stoken)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    m_queue_not_empty_cond.wait(lock, stoken, [this] { return !m_queue.empty(); });
}
