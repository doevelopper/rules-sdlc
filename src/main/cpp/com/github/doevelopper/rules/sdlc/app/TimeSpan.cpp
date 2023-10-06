
#include <com/github/doevelopper/rules/sdlc/app/TimeSpan.hpp>

using namespace com::github::doevelopper::rules::sdlc::app;

log4cxx::LoggerPtr TimeSpan::logger =
    log4cxx::Logger::getLogger(std::string("com.github.doevelopper.rules.sdlc.app.TimeSpan"));

// constexpr std::int64_t TimeSpan::NS = 1000*1000*1000;
// constexpr std::int64_t TimeSpan::MS = 1000;

TimeSpan::TimeSpan()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeSpan::~TimeSpan()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeSpan::TimeSpan(const times & value) noexcept
    : m_value(value)
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeSpan::TimeSpan(int seconds) noexcept
    : TimeSpan({seconds, 0})
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeSpan::TimeSpan(double seconds) noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

TimeSpan::TimeSpan(const Clock & clock) noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    // clock_gettime((clockid_t)clock, &this->m_value);
    clock_gettime(static_cast<clockid_t>(clock), &this->m_value);
}

const TimeSpan::times & TimeSpan::getTimespec() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (this->m_value);
}

std::int64_t TimeSpan::milliseconds() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (this->m_value.tv_sec * MS + this->m_value.tv_nsec / (NS / MS));
}

double TimeSpan::seconds() const noexcept
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    return (static_cast<double>(this->m_value.tv_sec) + static_cast<double>(this->m_value.tv_nsec) / NS);
}
