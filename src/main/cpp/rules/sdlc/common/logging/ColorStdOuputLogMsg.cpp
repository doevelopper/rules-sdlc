
#include <rules/sdlc/common/log/ColorStdOuputLogMsg.hpp>

const char * const ColorStdOuputLogMsg::COLOR_TYPE[] = {
    "\33[30m", // Black
    "\33[31m", // Red
    "\33[32m", // Green
    "\33[33m", // Yellow
    "\33[34m", // Blue
    "\33[35m", // Magenta/Purple
    "\33[36m", // Cyan
    "\33[37m", // Light Gray
    "\33[90m", // Dark Gray
    "\33[91m", // Light Red
    "\33[92m", // Light Green
    "\33[93m", // Light Yellow
    "\33[96m", // Light Cyan
    "\33[97m", // White
    "\33[0m" // Reset/remove all modifier, foreground and background attributes:
};

ColorStdOuputLogMsg::ColorStdOuputLogMsg()
    : ColorStdOuputLogMsg(true)
{
}

ColorStdOuputLogMsg::ColorStdOuputLogMsg(bool useColor, log4cxx::LogString dateFormat)
    : log4cxx::helpers::DateLayout(dateFormat)
    , colorless(useColor)
    , printLocation(false)
{
}

ColorStdOuputLogMsg::ColorStdOuputLogMsg(const ColorStdOuputLogMsg & orig)
    : ColorStdOuputLogMsg(true)
{
}

ColorStdOuputLogMsg::~ColorStdOuputLogMsg() { }

void ColorStdOuputLogMsg::setColor(bool value)
{
    colorless = !value;
}

void ColorStdOuputLogMsg::setPrintLocation(bool value)
{
    printLocation = value;
}

void ColorStdOuputLogMsg::format(
    log4cxx::LogString & _output, log4cxx::spi::LoggingEventPtr const & event, log4cxx::helpers::Pool & p) const
{
    std::ostringstream output;
    const int level = event->getLevel()->toInt();

    switch (level)
    {
    case log4cxx::Level::FATAL_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Red];
        break;

    case log4cxx::Level::ERROR_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Light_Red];
        break;

    case log4cxx::Level::WARN_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Yellow];
        break;

    case log4cxx::Level::INFO_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Green];
        break;

    case log4cxx::Level::DEBUG_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Light_Green];
        break;

    case log4cxx::Level::TRACE_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Light_Cyan];
        break;

    case log4cxx::Level::ALL_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::White];
        break;

    case log4cxx::Level::OFF_INT:
        output << COLOR_TYPE[ColorStdOuputLogMsg::Black];
        break;

    default:
        break;
    }

    log4cxx::LogString date;
    formatDate(date, event, p);
    if (!date.empty())
    {
        /*output << std::setw(6) << std::left << event->getLevel()->toString
               << COLOR_TYPE[ColorStdOuputLogMsg::Reset] << date
               << event->getLoggerName() << " "
               << event->getRenderedMessage();
         */
        if (printLocation)
        {
            if (colorless)
            {
                output << "\n  -> " << event->getLocationInformation().getFileName() << ":"
                       << event->getLocationInformation().getLineNumber();
            }
            else
            {
                output << "\n  -> " << COLOR_TYPE[ColorStdOuputLogMsg::Yellow]
                       << event->getLocationInformation().getFileName() << COLOR_TYPE[ColorStdOuputLogMsg::Reset] << ":"
                       << COLOR_TYPE[ColorStdOuputLogMsg::Red] << event->getLocationInformation().getLineNumber()
                       << COLOR_TYPE[ColorStdOuputLogMsg::Reset];
            }
        }
        output << std::endl;
        _output = output.str();
    }
}

void ColorStdOuputLogMsg::setOption(const log4cxx::LogString & option, const log4cxx::LogString & value)
{
    log4cxx::helpers::DateLayout::setOption(option, value);
    /*
       if(log4cxx::helpers::StringHelper::equalsIgnoreCase(option,
       LOG4CXX_STR("COLOR"), LOG4CXX_STR("color")))
       {
        this->setColor(log4cxx::helpers::OptionConverter::toBoolean(value,false));
       }
       else
       {

       }

       if(log4cxx::helpers::StringHelper::equalsIgnoreCase(option,
       LOG4CXX_STR("PRINTLOCATION"), LOG4CXX_STR("printlocation")))
       {
        this->setPrintLocation(log4cxx::helpers::OptionConverter::toBoolean(value,false));
       }
       else
       {

       }*/
}

std::ostream & ColorStdOuputLogMsg::reset(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[00m";
#elif defined(OS_WINDOWS)
        ColoredTerminal::winChangeAttributes(stream, -1, -1);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::bold(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[1m";
#elif defined(OS_WINDOWS)
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::dark(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[2m";
#elif defined(OS_WINDOWS)
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::underline(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[4m";
#elif defined(OS_WINDOWS)
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::blink(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[5m";
#elif defined(OS_WINDOWS)
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::reverse(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[7m";
#elif defined(OS_WINDOWS)
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::concealed(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[8m";
#elif defined(OS_WINDOWS)
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::grey(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[30m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(
            stream,
            0 // grey (black)
        );
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::red(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[31m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, FOREGROUND_RED);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::green(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[32m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, FOREGROUND_GREEN);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onGrey(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[40m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(
            stream, -1,
            0 // grey (black)
        );
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onYellow(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[43m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_GREEN | BACKGROUND_RED);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onRed(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[41m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_RED);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onGreen(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[42m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_GREEN);
#endif
    }
    return stream;
}

/*
   std::ostream& ColorStdOuputLogMsg::onYellow(std::ostream& stream)
    {
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
        {
 #if defined(OS_MACOS) || defined(OS_LINUX)
            stream << "\033[43m";
 #elif defined(OS_WINDOWS)
            __internal::winChangeAttributes(stream, -1,
                BACKGROUND_GREEN | BACKGROUND_RED
            );
 #endif
        }
        return stream;
   }


   std::ostream& ColorStdOuputLogMsg::onBlue(std::ostream& stream)
    {
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
        {
 #if defined(OS_MACOS) || defined(OS_LINUX)
            stream << "\033[44m";
 #elif defined(OS_WINDOWS)
            __internal::winChangeAttributes(stream, -1,
                BACKGROUND_BLUE
            );
 #endif
        }
        return stream;
   }

 */
std::ostream & ColorStdOuputLogMsg::onBlue(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[44m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_BLUE);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onMagenta(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[45m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_BLUE | BACKGROUND_RED);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onCyan(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[46m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_GREEN | BACKGROUND_BLUE);
#endif
    }
    return stream;
}

std::ostream & ColorStdOuputLogMsg::onWhite(std::ostream & stream)
{
    ColorStdOuputLogMsg::Term internalStream;
    if (internalStream.isAttyTerminal(stream))
    {
#if defined(OS_MACOS) || defined(OS_LINUX)
        stream << "\033[47m";
#elif defined(OS_WINDOWS)
        __internal::winChangeAttributes(stream, -1, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED);
#endif
    }
    return stream;
}
