
/*!
 * @defgroup LoggingService Logging utils
 * @ingroup Utils
 */

#ifndef RULES_SDLC_STD_LOG_LOGGER_HPP
#define RULES_SDLC_STD_LOG_LOGGER_HPP

#include <rules/sdlc/common/API_Export.hpp>
#include <boost/core/demangle.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <log4cxx/logger.h>
#include <time.h>
#include <memory>
#include <string>
#include <typeinfo>

/*!
 * @ingroup LoggingService
 * @brief Define static logger as private member.
 * @attention
 * <ul>
 *   <li>May change the scope of attributes to private in not define in private
 * section.</li>
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
 *   <li>May change the scope of attributes to protected if not define in
 * private section.</li>
 * </ul>
 * @retval None.
 */

#define LOG4CXX_DECLARE_STATIC_TEST_LOGGER                                                                             \
protected:                                                                                                             \
                                                                                                                       \
    static log4cxx::LoggerPtr logger;

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 * @param[in,out] name name of logguer to  be used within the class
 */

#define LOG4CXX_DECLARE_CLASS_LOGGER(name)                                                                             \
private:                                                                                                               \
                                                                                                                       \
    log4cxx::LoggerPtr name;

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define DECLARE_CLASS_LOGGGER(classname) log4cxx::LoggerPtr classname::logger(log4cxx::Logger::getLogger(#classname));

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define DECLARE_CLASS_LOGGGER_NAME(classname, loggername)                                                              \
    log4cxx::LoggerPtr classname::logger(log4cxx::Logger::getLogger(#loggername));

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define LOG4CXX_DEFINE_CLASS_LOGGER(name) log4cxx::Logger::getLogger(std::string(boost::core::demangle(name)));

/*!
 * @ingroup LoggingService
 * @brief Define logger tat prints its contents on standard output.
 */
#define LOG std::clog << __DATE__ << " " << __TIME__ << " " << __FUNCTION__ << std::endl;

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define CREATE_LOGGERPTR_LOCAL(loggerVar, loggerName)                                                                  \
    log4cxx::LoggerPtr loggerVar = log4cxx::LoggerPtr(log4cxx::Logger::getLogger(loggerName));

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define LOG4CXX_DEFINE_NS_LOGGER(loggerVar, loggerName)                                                                \
    namespace                                                                                                          \
    {                                                                                                                  \
        CREATE_LOGGERPTR_LOCAL(loggerVar, loggerName);                                                                 \
    }

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define INIT_LOGGER(fileName) log4cxx::PropertyConfigurator::configure(fileName);

/*!
 * @ingroup LoggingService
 * @brief Define logger as private member.
 */
#define LOG_FUNCTION(x) LOG4CXX_TRACE(this->logger, __FUNCTION__ << "(" << x << ")");

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

#define LOG_DEBUG(logger, data)                                                                                        \
    {                                                                                                                  \
        if (logger)                                                                                                    \
            std::cout << logger << ": " << data << std::endl;                                                          \
        else                                                                                                           \
            LOG_CA(std::cout) << boost::posix_time::microsec_clock::local_time() << ": " << data << std::endl;         \
    }

#define LOG_INFO(logger, data)                                                                                         \
    {                                                                                                                  \
        if (logger)                                                                                                    \
            std::cout << logger << ": " << data << std::endl;                                                          \
        else                                                                                                           \
            LOG_CA(std::cout) << boost::posix_time::microsec_clock::local_time() << ": " << data << std::endl;         \
    }

#define LOG_WARN(logger, data)                                                                                         \
    {                                                                                                                  \
        if (logger)                                                                                                    \
            std::cout << logger << ": " << data << std::endl;                                                          \
        else                                                                                                           \
            LOG_CA(std::cout) << boost::posix_time::microsec_clock::local_time() << ": " << data << std::endl;         \
    }

#define LOG_ERROR(logger, data)                                                                                        \
    {                                                                                                                  \
        if (logger)                                                                                                    \
            std::cerr << logger << ": " << data << std::endl;                                                          \
        else                                                                                                           \
            LOG_CA(std::cerr) << boost::posix_time::microsec_clock::local_time() << ": " << data << std::endl;         \
    }

#define LOG_FATAL(logger, data)                                                                                        \
    {                                                                                                                  \
        if (logger)                                                                                                    \
            std::cerr << logger << ": " << data << std::endl;                                                          \
        else                                                                                                           \
            LOG_CA(std::cout) << boost::posix_time::microsec_clock::local_time() << ": " << data << std::endl;         \
    }

#define DEBUG(x)                                                                                                       \
    {                                                                                                                  \
        time_t now    = time(0);                                                                                       \
        std::string s = std::string(ctime(&now));                                                                      \
        std::clog << s.substr(0, s.size() - 1) << " " << x << std::endl;                                               \
    }

namespace rules::sdlc::stdc::logging
{

    class LoggingServicePrivate;

    class LoggingService
    {
    public:

        explicit LoggingService(unsigned long delay);
        LoggingService(const LoggingService &)             = delete;
        LoggingService(LoggingService &&)                  = delete;
        LoggingService & operator=(const LoggingService &) = delete;
        LoggingService & operator=(LoggingService &&)      = delete;
        virtual ~LoggingService();
        /*!
         * @ingroup los_membox
         * @brief Initialize a memory pool.
         * @fn void configure ( )
         * @par Description:
         * <ul>
         *    <li>This API is used to initialize a memory pool.</li>
         * </ul>
         *
         * @attention
         * <ul>
         *   <li>None.</li>
         * </ul>
         *
         * @param pPool    [IN] Memory pool address.
         *
         * @retval #OK  1: The memory pool is successfully initialized.
         * @retval #NOK   0: The memory pool fails to be initialized.
         * @par Dependency:
         * <ul>
         *   <li> LoggingServicePrivate: the header file that contains the API
         * declaration.</li>
         * </ul>
         * @see None.
         * @since Huawei LiteOS V100R001C00
         *
         */
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

        std::shared_ptr<LoggingServicePrivate> d_ptr;
        // rules::sdlc::stdc::PimplPtr< LoggingServicePrivate > d_ptr;

    private:

        Q_DECLARE_PRIVATE(LoggingService);
    };

} // namespace rules::sdlc::stdc::logging
#endif
