#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICEPRIVATE_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_LOGGING_LOGGINGSERVICEPRIVATE_HPP

#include <apr-1/apr.h>
#include <log4cxx/appender.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/consoleappender.h>
#include <log4cxx/fileappender.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/logger.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/logstring.h> // has typedefed string type used in log4cxx
// #include <log4cxx/net/socketappender.h>
#include <stdexcept>
#include <string>
#include <log4cxx/nt/nteventlogappender.h>
#include <log4cxx/nt/outputdebugstringappender.h> // NT OUTPUTDEBUGSTRING Appender
#include <log4cxx/patternlayout.h>
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/rolling/fixedwindowrollingpolicy.h>
#include <log4cxx/rolling/rollingfileappender.h>
#include <log4cxx/rolling/rollingpolicy.h>
#include <log4cxx/rolling/rollingpolicybase.h>
#include <log4cxx/rolling/sizebasedtriggeringpolicy.h>
#include <log4cxx/rolling/triggeringpolicy.h>
#include <log4cxx/simplelayout.h>
#include <log4cxx/xml/domconfigurator.h>

namespace com::github::doevelopper::rules::sdlc::logging
{
    class LoggingServicePrivate
    {
    public:

        LoggingServicePrivate() noexcept;
        LoggingServicePrivate(unsigned long delay);
        LoggingServicePrivate(const LoggingServicePrivate &) noexcept             = default;
        LoggingServicePrivate(LoggingServicePrivate &&) noexcept                  = default;
        LoggingServicePrivate & operator=(const LoggingServicePrivate &) noexcept = default;
        LoggingServicePrivate & operator=(LoggingServicePrivate &&) noexcept      = default;
        virtual ~LoggingServicePrivate() noexcept;

        // log4cxx::LoggerPtr operator->()
        // {
        //     return this->m_logger;
        // }

        // log4cxx::LoggerPtr operator=(const LoggingServicePrivate & logger)
        // {
        //     return this->m_logger;
        // }

        /*!
         * @brief  Retrieve a particular logger by name
         */
        template <typename S>
        log4cxx::LoggerPtr getLogger(const S & name)
        {
            return log4cxx::Logger::getLogger(name);
        }

        /*!
         * @brief Retrieve a particular logger by name with
         *        possibility of returning default initialized logger_types.
         */

        auto getLogger(const char * const name) -> log4cxx::LoggerPtr
        {
            return name ? log4cxx::Logger::getLogger(name) : log4cxx::LoggerPtr();
        }

        auto getLogger(const std::string & name)
        {
            return name.empty() ? log4cxx::LogManager::getRootLogger() : log4cxx::LogManager::getLogger(name);
        }

        /*!
         * @brief Retrieve a descendent of a particular logger by name
         */
        template <typename S, typename T>
        log4cxx::LoggerPtr getLogger(const S & name, const T & child)
        {
            std::string s(name);
            s.append(1, '.');
            s.append(child);

            return log4cxx::Logger::getLogger(s);
        }

        /*!
         * @brief Retrieve a descendent of a particular logger by name
         */
        template <typename T>
        log4cxx::LoggerPtr getLogger(log4cxx::LoggerPtr & logger, const T & child)
        {
            std::string s;
            logger->getName(s);
            s.append(1, '.');
            s.append(child);

            return log4cxx::Logger::getLogger(s);
        }

        bool initLogger();
        bool loggerReset();
        void loggerConfigure(std::string const & filename);
        bool checkLogManagerStatus();
        void setRootDefaultLevel(const std::string & level);
        void setLoggerLevel(const std::string & loggerId, const std::string & level);

        void trace(const std::string & s);
        void debug(const std::string & s);
        void info(const std::string & s);
        void warn(const std::string & s);
        void error(const std::string & s);
        void fatal(const std::string & s);
        void flush();

        auto watchPeriod() const& -> const unsigned long& { return m_watchPeriod; }
        auto watchPeriod() &      -> unsigned long&       { return m_watchPeriod; }
        auto watchPeriod() &&     -> unsigned long&&      { return std::move(m_watchPeriod); }

    protected:
    private:

        static const char * configEnv;
        log4cxx::LoggerPtr m_logger;
        /*!
         *  @brief Value for periodical check if configFilename has been created
         * or modified!
         */
        unsigned long m_watchPeriod;
    };
}
#endif
