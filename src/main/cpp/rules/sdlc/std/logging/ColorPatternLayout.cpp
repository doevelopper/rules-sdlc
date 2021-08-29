
/*

   log4j.appender.CA=org.apache.log4j.ConsoleAppender
   log4j.appender.CA.layout=org.apache.log4j.ColorPatternLayout
   log4j.appender.CA.layout.ConversionPattern=%-5p %c %x - %m%n
 */

#include <rules/sdlc/std/logging/ColorPatternLayout.hpp>

using namespace log4cxx;

IMPLEMENT_LOG4CXX_OBJECT ( ColorPatternLayout );

ColorPatternLayout::ColorPatternLayout ( )
    : log4cxx::PatternLayout ( )
{
}

ColorPatternLayout::ColorPatternLayout ( const LogString & s )
    : log4cxx::PatternLayout ( s )
{
}

void
    ColorPatternLayout::format ( LogString & output, const spi::LoggingEventPtr & event, helpers::Pool & pool ) const
{
    log4cxx::LogString consoleMessage;
    log4cxx::PatternLayout::format ( consoleMessage, event, pool );
    log4cxx::LevelPtr lvl = event->getLevel ( );
    switch ( lvl->toInt ( ) )
    {
    case log4cxx::Level::FATAL_INT:
        output.append ( "\u001b[0;41m" );     // red BG
        break;

    case log4cxx::Level::ERROR_INT:
        output.append ( "\u001b[0;31m" );     // red FG
        break;

    case log4cxx::Level::WARN_INT:
        output.append ( "\u001b[0;33m" );     // Yellow FG
        break;

    case log4cxx::Level::INFO_INT:
        output.append ( "\u001b[1m" );     // Bright
        break;

    case log4cxx::Level::DEBUG_INT:
        output.append ( "\u001b[2;32m" );     // Green FG
        break;

    case log4cxx::Level::TRACE_INT:
        output.append ( "\u001b[0;30m" );     // Black FG
        break;

    default:
        break;
    }
    output.append ( consoleMessage );
    output.append ( "\u001b[m" );
}
