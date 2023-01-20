
#ifndef RULES_SDLC_STD_LOGGING_LOGGINGSERVICEPRIVATE_HPP
#define RULES_SDLC_STD_LOGGING_LOGGINGSERVICEPRIVATE_HPP

#include <apr-1/apr.h>
#include <log4cxx/appender.h>
#include <log4cxx/basicconfigurator.h>
#include <log4cxx/consoleappender.h> // CONSOLE Appender
#include <log4cxx/fileappender.h> // FILE Appender
#include <log4cxx/helpers/exception.h>
#include <log4cxx/logger.h>
#include <log4cxx/logmanager.h>
#include <log4cxx/logstring.h> // has typedefed string type used in log4cxx
#include <log4cxx/net/socketappender.h> // SOCKET Appender
#include <log4cxx/nt/nteventlogappender.h> // NT EVENT LOG Appender
#include <log4cxx/nt/outputdebugstringappender.h> // NT OUTPUTDEBUGSTRING Appender
#include <log4cxx/patternlayout.h> // needed for pattern layout
#include <log4cxx/propertyconfigurator.h>
#include <log4cxx/rolling/fixedwindowrollingpolicy.h>
#include <log4cxx/rolling/rollingfileappender.h> // ROLLING FILE Appender
#include <log4cxx/rolling/rollingpolicy.h>
#include <log4cxx/rolling/rollingpolicybase.h>
#include <log4cxx/rolling/sizebasedtriggeringpolicy.h>
#include <log4cxx/rolling/triggeringpolicy.h>
#include <log4cxx/simplelayout.h> // needed for simple layout
#include <log4cxx/xml/domconfigurator.h>
#include <stdexcept>
#include <string>

namespace rules::sdlc::stdc::logging
{
    namespace intternalUse
    {
        // File* getStdStream(const std::ostream& stream);
        bool isAtty(const std::ostream & stream);
    } // namespace intternalUse

    class LoggingServicePrivate
    {
    public:
        LoggingServicePrivate(unsigned long delay = 5000L);
        LoggingServicePrivate(const LoggingServicePrivate & rsh);
        virtual ~LoggingServicePrivate();

        log4cxx::LoggerPtr operator->(void)
        {
            return this->m_logger;
        }
        log4cxx::LoggerPtr operator=(const LoggingServicePrivate & logger)
        {
            return this->m_logger;
        }
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

        log4cxx::LoggerPtr getLogger(const char * const name)
        {
            return name ? log4cxx::Logger::getLogger(name) : log4cxx::LoggerPtr();
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
        log4cxx::LoggerPtr & getLogger(log4cxx::LoggerPtr & logger)
        {
            return logger;
        }
        /*!
         * @brief Idempotent overload of get_logger() to aid macro definitions
         */

        log4cxx::LoggerPtr & getLogger(log4cxx::LoggerPtr &, log4cxx::LoggerPtr & child)
        {
            return child;
        }
        /*! @brief Configures log4cxx using FILENAME and initializes logging
         * module by invoking initLog(). If FILENAME ends with ".xml", it is
         * passed to log4cxx::xml::DOMConfigurator::configure(). Otherwise, it
         * assumed to be a log4j Java properties file and is passed to
         * log4cxx::PropertyConfigurator::configure(). See
         * http://logging.apache.org/log4cxx/usage.html for additional details.
         *
         * @param filename  Path to configuration file.
         */
        void loggerConfigure(std::string const & filename);
        bool initLogger();
        bool loggerReset();
        log4cxx::LoggerPtr getLoggerByName(const char * loggerName);
        void setLoggerLevel(const std::string & loggerId, const std::string & level);
        void setRootDefaultLevel(const std::string & level);
        unsigned long periodicalCheck() const;
        void periodicalCheck(unsigned long delay);
        void loadConfig(const std::string & configFilename);
        void loadConfigAndWatch(const std::string & configFilename);
        void loggerNames(std::vector<std::string> & names);

        static const char * configEnv;
        log4cxx::LoggerPtr m_logger;
        bool checkLogManagerStatus();
        std::string getFileExtension(const std::string & s);
        /*!
         *  @brief Value for periodical check if configFilename has been created
         * or modified!
         */
        unsigned long m_watchPeriod;
        void trace(const std::string & s);
        void debug(const std::string & s);
        void info(const std::string & s);
        void warn(const std::string & s);
        void error(const std::string & s);
        void fatal(const std::string & s);
        void flush();
    };

}
#endif
