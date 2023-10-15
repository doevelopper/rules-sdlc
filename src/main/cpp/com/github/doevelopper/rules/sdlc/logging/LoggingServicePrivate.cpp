
#include <com/github/doevelopper/rules/sdlc/logging/LoggingServicePrivate.hpp>

#include <unistd.h>
#include <filesystem>
#include <iostream>
#include <typeinfo>

using namespace com::github::doevelopper::rules::sdlc::logging;

LoggingServicePrivate::LoggingServicePrivate()
    : m_watchPeriod(50000UL)
{
    std::cerr << "Env variable: LOG4CXX_CONFIGURATION  yet not set!!!";
}

LoggingServicePrivate::LoggingServicePrivate(std::uint32_t delay)
    : m_watchPeriod(delay)
{
    std::cout << "Using log monitoring delay " << delay << std::endl;
}

LoggingServicePrivate::~LoggingServicePrivate()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);

    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "---- END LOGGING -----");
    }

    log4cxx::LogManager::shutdown();
}

bool LoggingServicePrivate::initLogger()
{
    std::string configurationPath("");
    // if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    // {
    //     throw std::logic_error("t initialisation, found that log4cxx configuration");
    // }
    // else
    // {
    try
    {
        char * filePath = nullptr;
        if ((filePath = getenv("LOG4CXX_CONFIGURATION")) == nullptr)
        {
            std::cerr << "Env variable: LOG4CXX_CONFIGURATION not set!!!" << std::endl;
        }
        else
        {
            configurationPath.assign(filePath);
        }
    }
    catch (log4cxx::helpers::Exception & e)
    {
        std::cerr << typeid(e).name() << ": " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << typeid(e).name() << ": " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Mein Gott! was den loss ??? " << std::endl;
    }
    // }

    if (configurationPath.empty() /*&& getenv(log4cxx.properties)*/)
    {
        // https://logging.apache.org/log4j/2.x/manual/layouts.html
        log4cxx::PatternLayoutPtr layout(new log4cxx::PatternLayout(
            LOG4CXX_STR("%d{yyyy-MM-dd HH:mm:ss.SSS} [%-6p] - [%15.15t] - %-35c{1.} -- %m%n")));

        // log4cxx::PatternLayoutPtr layout( new log4cxx::PatternLayout(
        // "[%-6.6p] %d{HH:mm:ss.SSS} [%15.15t] (%20.20c)  (%-10.20l) - %-20.20M - %m%n"));
        // log4cxx::PatternLayoutPtr layout (new log4cxx::PatternLayout (
        //                                      "%d{yyyy-MM-dd HH:mm:ss.SSS}
        //                                      (%-6c) [%-6p] [%15.15t]
        //                                      (%-10.20l) -- %m%n"));

        log4cxx::ConsoleAppenderPtr consoleAppender(new log4cxx::ConsoleAppender(layout));
        log4cxx::helpers::Pool pool;
        consoleAppender->activateOptions(pool);
        log4cxx::BasicConfigurator::configure(consoleAppender);
        log4cxx::Logger::getRootLogger()->setLevel(LOG_LEVEL ? log4cxx::Level::getTrace() : log4cxx::Level::getInfo());

        log4cxx::LogManager::getLoggerRepository()->setConfigured(true);
        log4cxx::LogManager::getLoggerRepository()->getRootLogger()->info(
            "Starting the internal configured logging system.");

        // LOG4CXX_TRACE(LOG, "Log4cxx file Path " << filePath);
    }
    else
    {
        if (::access(configurationPath.c_str(), R_OK) == 0)
        {
            this->loggerConfigure(configurationPath);
        }

        log4cxx::Logger::getRootLogger()->setLevel(log4cxx::Level::getAll());
        log4cxx::LogManager::getLoggerRepository()->setConfigured(true);
    }
    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "----START LOGGING-----");
    LOG4CXX_TRACE(
        log4cxx::Logger::getRootLogger(),
        "Logger initialized with " << log4cxx::Logger::getRootLogger()->getAllAppenders().size() << " Appenders");

    LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), std::locale("").name().c_str());
    return (this->checkLogManagerStatus());
}

bool LoggingServicePrivate::checkLogManagerStatus()
{
    // LOG4CXX_TRACE(LOG,"Logger::checkLogManagerStatus");
    // Check that we have not accidentally triggered configuration.
    // Paranoia due to "When the LogManager class is loaded into memory the

    // default initialization procedure is initiated" in LogManager Doxygen.
    return (log4cxx::LogManager::getLoggerRepository()->isConfigured());
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

void LoggingServicePrivate::loggerConfigure(std::string const & configFilename)
{
    if (log4cxx::LogManager::getLoggerRepository()->isConfigured())
    {
        if (std::filesystem::path(configFilename).extension().compare(".xml") == 0)
        {
#if APR_HAS_THREADS
            log4cxx::xml::DOMConfigurator::configureAndWatch(configFilename, static_cast<long>(m_watchPeriod));
#else
            log4cxx::xml::DOMConfigurator::configure(configFilename);
#endif
        }
        else
        {
#if APR_HAS_THREADS
            log4cxx::PropertyConfigurator::configureAndWatch(configFilename, static_cast<long>(m_watchPeriod));
#else
            log4cxx::PropertyConfigurator::configure(configFilename);
#endif
        }
    }
    else
    {
        LOG4CXX_WARN(log4cxx::Logger::getRootLogger(), "log4cxx configuration detected.");
    }
}

bool LoggingServicePrivate::loggerReset()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
    // // !TODO: does resetConfiguration() remove existing appenders?
    // log4cxx::BasicConfigurator::resetConfiguration();
    log4cxx::LogManager::resetConfiguration();
    log4cxx::BasicConfigurator::resetConfiguration();
    return (true);
}

void LoggingServicePrivate::flush()
{
    LOG4CXX_TRACE(log4cxx::Logger::getRootLogger(), __LOG4CXX_FUNC__);
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
