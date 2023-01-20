
#include <rules/sdlc/common/logging/LoggingServicePrivate.hpp>

#include <unistd.h>
#include <filesystem>
#include <iostream>
#include <typeinfo>

using namespace rules::sdlc::stdc::logging;

/*!
 * @brief Fallback logging macro to console appender.
 * @param stream Standard stream to log to.
 * @return Given @a stream.
 * @exemple LOG_SO(std::cout) << "streaming to standard output." << std::endl;
 *          LOG_SE(std::cerr) << "streaming to standard error."  << std::endl;
 */

/*
 #define LOG_(stream) \
   stream << "(" << "taskName(taskIdSelf())" << ") " \
   log4cxx::LoggerPtr loggerPtr __attribute__((init_priority(10)));
 */

LoggingServicePrivate::LoggingServicePrivate(unsigned long delay)
    : m_watchPeriod(delay)
{
}

LoggingServicePrivate::LoggingServicePrivate(const LoggingServicePrivate & orig) { }

LoggingServicePrivate::~LoggingServicePrivate()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "---- END LOGGING -----");
    }

    log4cxx::LogManager::shutdown();
}

void LoggingServicePrivate::flush()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
}

bool LoggingServicePrivate::loggerReset()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    log4cxx::LogManager::resetConfiguration();
    log4cxx::BasicConfigurator::resetConfiguration();

    return (true);
}

std::string LoggingServicePrivate::getFileExtension(const std::string & s)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    size_t i = s.rfind('.', s.length());

    if (i != std::string::npos)
    {
        return (s.substr(i + 1, s.length() - i));
    }

    return ("");
}

/*
   log4cxx::LoggerPtr LoggingServicePrivate::getLoggerByName (const char *
   loggerName)
   {
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
   log4cxx::LogString
    return (
   log4cxx::LogManager::getLoggerRepository()->getLogger(std::string(loggerName)));
   }
 */
void LoggingServicePrivate::loggerConfigure(std::string const & filename)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    // TODO: does resetConfiguration() remove existing appenders?
    log4cxx::BasicConfigurator::resetConfiguration();

    if (getFileExtension(filename).compare(".xml") == 0)
    {
        log4cxx::xml::DOMConfigurator::configure(filename);
    }
    else
    {
        log4cxx::PropertyConfigurator::configure(filename);
    }
}

bool LoggingServicePrivate::initLogger()
{
    namespace fs = std::filesystem;
    std::string configurationPath("");
    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        throw std::logic_error("t initialisation, found that log4cxx configuration");
    }
    else
    {
        char * filePath;
        try
        {
            if ((filePath = getenv("LOG4CXX_CONFIGURATION")) == nullptr)
            {
                // std::cerr << "Failed to get loggger configuratin file" <<
                // std::endl;
            }
            else
            {
                configurationPath.assign(filePath);
            }
        }
        catch (log4cxx::helpers::Exception & e)
        {
            std::cout << typeid(e).name() << ": " << e.what() << std::endl;
        }
        catch (std::exception & e)
        {
            std::cout << typeid(e).name() << ": " << e.what() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Mein Gott! was den loss ??? " << std::endl;
        }
    }

    if (configurationPath.empty() /*&& getenv(log4cxx.properties)*/)
    {
        // https://logging.apache.org/log4j/2.x/manual/layouts.html
        // log4cxx::PatternLayoutPtr layout (new log4cxx::PatternLayout (
        //                                      "%d{yyyy-MM-dd HH:mm:ss.SSS}
        //                                      (%-6c) [%-6p] [%15.15t]
        //                                      (%-10.20l) -- %m%n"));
        log4cxx::PatternLayoutPtr layout(
            new log4cxx::PatternLayout(LOG4CXX_STR("%d{HH:mm:ss.SSS} [%-6p] - [%15.15t] - %-35c{1.} -- %m%n")));

        // log4cxx::PatternLayoutPtr layout( new log4cxx::PatternLayout(
        // "[%-6.6p] %d{HH:mm:ss.SSS} [%15.15t] (%20.20c)  (%-10.20l) - %-20.20M
        // - %m%n"));

        log4cxx::ConsoleAppenderPtr consoleAppender(new log4cxx::ConsoleAppender(layout));

        log4cxx::helpers::Pool pool;
        consoleAppender->activateOptions(pool);
        log4cxx::BasicConfigurator::configure(consoleAppender);
        log4cxx::Logger::getRootLogger()->setLevel(LOG_LEVEL ? log4cxx::Level::getTrace() : log4cxx::Level::getInfo());

        log4cxx::LogManager::getLoggerRepository()->setConfigured(true);
        // log4cxx::LogManager::getLoggerRepository()->getRootLogger()->info(
        //         "Starting the internal configured logging system.");

        // LOG4CXX_TRACE(LOG, "Log4cxx file Path " << filePath);
    }
    else
    {
        if (::access(configurationPath.c_str(), R_OK) == 0)
        {
#if APR_HAS_THREADS

            // this->loadConfigAndWatch(log4cxx::File( configurationPath.c_str(
            // )).getPath( ));
            this->loadConfigAndWatch(configurationPath);
#else

            // this->loadConfig(log4cxx::File( configurationPath.c_str(
            // )).getPath( ));
            this->loadConfig(configurationPath);
#endif
        }

        log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getAll());
        log4cxx::LogManager::getLoggerRepository()->setConfigured(true);

        // log4cxx::LogManager::getLoggerRepository()->getRootLogger()->trace("Starting
        // the logging system" + configurationPath );
        // LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(),"Logger initialized.
        // Appenders sise:" <<
        // log4cxx::Logger::getRootLogger()->getAllAppenders().size() );
    }

    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "----START LOGGING-----");
    LOG4CXX_TRACE(
        log4cxx::Logger::getRootLogger(),
        "Logger initialized. Appenders sise:" << log4cxx::Logger::getRootLogger()->getAllAppenders().size());
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), std::locale("").name().c_str());
    return (this->checkLogManagerStatus());
}

void LoggingServicePrivate::setLoggerLevel(const std::string & loggerId, const std::string & level)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    log4cxx::Logger::getLogger(loggerId)->setLevel(log4cxx::Level::toLevel(level, log4cxx::Level::getInfo()));
}

void LoggingServicePrivate::setRootDefaultLevel(const std::string & level)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::toLevel(level, log4cxx::Level::getInfo()));
}

unsigned long LoggingServicePrivate::periodicalCheck() const
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    return (this->m_watchPeriod);
}

void LoggingServicePrivate::periodicalCheck(unsigned long delay)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    this->m_watchPeriod = delay;
}

void LoggingServicePrivate::loadConfig(const std::string & configFilename)
{
    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        if (!configFilename.empty())
        {
            if (configFilename.find(".xml") != std::string::npos)
            {
                log4cxx::xml::DOMConfigurator::configure(configFilename);

                // log4cxx::xml::DOMConfigurator::configure( log4cxx::File(
                // configFilename ).getPath( ) );
            }
            else
            {
                log4cxx::PropertyConfigurator::configure(configFilename);
            }
        }
    }
    else
    {
        LOG4CXX_WARN(log4cxx::Logger::getRootLogger(), "log4cxx configuration detected.");
    }
}

void LoggingServicePrivate::loadConfigAndWatch(const std::string & configFilename)
{
    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        if (!configFilename.empty())
        {
            if (configFilename.find(".xml") != std::string::npos)
            {
                log4cxx::xml::DOMConfigurator::configureAndWatch(
                    configFilename, static_cast<long>(this->periodicalCheck()));
            }
            else
            {
                log4cxx::PropertyConfigurator::configureAndWatch(
                    configFilename, static_cast<long>(this->periodicalCheck()));
            }
        }
    }
    else
    {
        LOG4CXX_WARN(log4cxx::Logger::getRootLogger(), "log4cxx configuration detected.");
    }
}

void LoggingServicePrivate::loggerNames(std::vector<std::string> & names)
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    // log4cxx::LoggerList list = log4cxx::LogManager::getCurrentLoggers( );
    // log4cxx::LoggerList::iterator logger = list.begin( );
    // names.clear( );
    /*
        for(; logger != list.end( ); logger++ )
        {
            LOG4CXX_TRACE( log4cxx::Logger::getRootLogger( ), "Logger "
                        << std::distance(list.begin(), logger) <<
       (*logger)->getName( ) ); names.push_back( (*logger)->getName( ) );
        }
     */
}

bool LoggingServicePrivate::checkLogManagerStatus()
{
    // LOG4CXX_TRACE(LOG,"Logger::checkLogManagerStatus");
    // Check that we have not accidentally triggered configuration.
    // Paranoia due to "When the LogManager class is loaded into memory the

    // default initialization procedure is initiated" in LogManager Doxygen.
    return (log4cxx::LogManager::getLoggerRepository()->isConfigured());
}

void LoggingServicePrivate::trace(const std::string & s)
{
    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->trace(s);
}

void LoggingServicePrivate::debug(const std::string & s)
{
    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->debug(s);
}

void LoggingServicePrivate::info(const std::string & s)
{
    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->info(s);
}

void LoggingServicePrivate::warn(const std::string & s)
{
    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->warn(s);
}

void LoggingServicePrivate::error(const std::string & s)
{
    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->error(s);
}

void LoggingServicePrivate::fatal(const std::string & s)
{
    log4cxx::LogManager::getLoggerRepository()->getRootLogger()->fatal(s);
}
