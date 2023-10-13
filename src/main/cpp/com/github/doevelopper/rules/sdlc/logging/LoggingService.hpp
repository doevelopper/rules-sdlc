
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICE_HPP

#include <com/github/doevelopper/rules/sdlc/API_Export.hpp>

// #include <boost/core/demangle.hpp>
// #include <boost/date_time/posix_time/posix_time.hpp>
// #include <boost/preprocessor/stringize.hpp>
// #include <boost/type_index.hpp>

#include <log4cxx/logger.h>

#include <ctime>
#include <memory>
#include <string>
#include <typeinfo>

/*!
 * @ingroup LoggingService
 * @brief Define static logger as private member.
 * @attention
 * <ul>
 *   <li>May change the scope of attributes to private in not define in private section.</li>
 * </ul>
 * @retval None.
 * @see
 * @since
 */

#define LOG4CXX_DECLARE_STATIC_LOGGER                                                                                  \
private:                                                                                                               \
                                                                                                                       \
    static log4cxx::LoggerPtr logger;

/*!
 * @ingroup LoggingService
 * @brief Define static logger as protected member.
 * @attention
 * <ul>
 *   <li>May change the scope of attributes to protected if not define in private section.</li>
 * </ul>
 * @retval None.
 */

#define LOG4CXX_DECLARE_STATIC_TEST_LOGGER                                                                             \
protected:                                                                                                             \
                                                                                                                       \
    static log4cxx::LoggerPtr logger;

/*!
 * @brief Fallback logging macro to console appender.
 * @param stream Standard stream to log to.
 * @return Given @a stream.
 * @exemple LOG_CA(std::cout) << "streaming to standard output." << std::endl;
 *          LOG_CA(std::cerr) << "streaming to standard error."  << std::endl;
 */
#define LOG_CA(stream)                                                                                                 \
    stream << "("                                                                                                      \
           << "processID "                                                                                             \
           << ") "                                                                                                     \
           << "[" << logger << "::" << __func__ << "] "

#define LOG4CXX_DEFINE_CLASS_LOGGER(i)    (boost::core::demangle(typeid(i).name()))
#define LOG4CXX_DEFINE_CLASS_LOGGER(name) log4cxx::Logger::getLogger(std::string(boost::core::demangle(name)));
/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 * @param[in,out] name name of logguer to  be used within the class
 */

#define LOG4CXX_DECLARE_CLASS_LOGGER(name)                                                                             \
private:                                                                                                               \
                                                                                                                       \
    log4cxx::LoggerPtr name;

#define DEFAULT_LOGGER() log4cxx::Logger::getRootLogger()

#define DEFINE_LOGGER std::string logger {boost::typeindex::type_id<decltype(*this)>().pretty_name()};

/*!
 * @ingroup LoggingService
 * @brief Mcrot for ease tracing entry end exit of function.
 */
#define LOG_EXIT_FUNCTION(x) LOG4CXX_TRACE(logger, __FUNCTION__ << "(" << x << ")");

namespace com::github::doevelopper::rules::sdlc::logging
{
    class LoggingServicePrivate;

    class LoggingService
    {
        std::shared_ptr<LoggingServicePrivate> d_ptr;
        Q_DECLARE_PRIVATE(LoggingService)
        Q_DEFAULT_COPY_MOVE(LoggingService)
    public:

        LoggingService() noexcept;
        virtual ~LoggingService() noexcept;

        explicit LoggingService(unsigned long delay);
        void configure();

        SDLC_DEPRECATED_MSG("Replaced by LOG4CXX_TRACE macro, which has an improved interface")
        void trace(const std::string & s);
        SDLC_DEPRECATED_MSG("Replaced by LOG4CXX_BEBUG macro, which has an improved interface")
        void debug(const std::string & s);
        SDLC_DEPRECATED_MSG("Replaced by LOG4CXX_INFO macro, which has an improved interface")
        void info(const std::string & s);
        SDLC_DEPRECATED_MSG("Replaced by LOG4CXX_WARN macro, which has an improved interface")
        void warn(const std::string & s);
        SDLC_DEPRECATED_MSG("Replaced by LOG4CXX_ERROR macro, which has an improved interface")
        void error(const std::string & s);
        SDLC_DEPRECATED_MSG("Replaced by LOG4CXX_FATAL macro, which has an improved interface")
        void fatal(const std::string & s);
        void flush();

    protected:
    private:
        unsigned long loggerConfigWatchDelay;
    };
}

#endif
