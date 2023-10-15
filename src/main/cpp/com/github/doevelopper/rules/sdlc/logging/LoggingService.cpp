
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <com/github/doevelopper/rules/sdlc/logging/LoggingServicePrivate.hpp>
#include <iostream>
using namespace com::github::doevelopper::rules::sdlc::logging;

// std::string logger = "com.github" + boost::core::demangle(typeid(this).name()) + ".";

LoggingService::LoggingService()
    : d_ptr(new LoggingServicePrivate())
{
    Q_D(LoggingService);
    // d->watchPeriod(100000LUL);
}

LoggingService::LoggingService(std::uint32_t loggerWatchDelay)
    : d_ptr(new LoggingServicePrivate(loggerWatchDelay))
{
    Q_D(LoggingService);
    // d->watchPeriod(loggerWatchDelay);
    // d->loggerSvce = log4cxx::Logger::getLogger (name.toStdString().c_str());
    this->configure();
}

LoggingService::~LoggingService()
{
    Q_D(LoggingService);
}

void LoggingService::configure()
{
    Q_D(LoggingService);
    try
    {
        d->initLogger();
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
        std::cerr << "Mein Gott Vas den loss ??? " << std::endl;
    }
}

void LoggingService::debug(const std::string & s)
{
    Q_D(LoggingService);
    d->debug(s);
}

void LoggingService::info(const std::string & s)
{
    Q_D(LoggingService);
    d->info(s);
}

void LoggingService::trace(const std::string & s)
{
    Q_D(LoggingService);
    d->trace(s);
}

void LoggingService::warn(const std::string & s)
{
    Q_D(LoggingService);
    d->warn(s);
}

void LoggingService::error(const std::string & s)
{
    Q_D(LoggingService);
    d->error(s);
}

void LoggingService::fatal(const std::string & s)
{
    Q_D(LoggingService);
    d->fatal(s);
}

void LoggingService::flush()
{
    Q_D(LoggingService);
    d->flush();
}
