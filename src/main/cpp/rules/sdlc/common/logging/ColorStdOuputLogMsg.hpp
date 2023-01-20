
#ifndef RULES_SDLC_STD_LOG_COLORSTDOUPUTLOGMSG_HPP
#define RULES_SDLC_STD_LOG_COLORSTDOUPUTLOGMSG_HPP
#include <iomanip>
#include <log4cxx/helpers/datelayout.h>
#include <log4cxx/layout.h>
#include <log4cxx/spi/loggingevent.h>
#include <sstream>
/*
 * @brief The following snippet of code detects the current OS and
 *        defines the appropriate macro that is used to wrap some
 *        platform specific things.
 */

#if defined(_WIN32) || defined(_WIN64)
#define OS_WINDOWS
#elif defined(__APPLE__)
#define OS_MACOS
#elif defined(linux) || defined(__linux)
#define OS_LINUX
#else
#error unsupported platform
#endif
/*
 * @brief This headers provides the `isatty()`/`fileno()` functions,
 *        which are used for testing whether a standart stream refers
 *        to the terminal. As for Windows, we also need WinApi funcs
 *        for changing colors attributes of the terminal.
 */

#if defined(OS_MACOS) || defined(OS_LINUX)
#include <unistd.h>
#elif defined(OS_WINDOWS)
#include <io.h>
#include <windows.h>
#endif

#include <cstdio>
#include <iostream>
#include <ostream>

class ColorStdOuputLogMsg : public log4cxx::helpers::DateLayout
{
    enum
    {
        Black,
        Red,
        Green,
        Yellow,
        Blue,
        Purple,
        Cyan,
        Light_Gray,
        Dark_Gray,
        Light_Red,
        Light_Green,
        Light_Yellow,
        Light_Cyan,
        White,
        Reset
    };

    class Term
    {
    public:

        Term();
        virtual ~Term();
        FILE * getStandardStream(const std::ostream & stream)
        {
            if (&stream == &std::cout)
            {
                return stdout;
            }
            else if (&stream == &std::cerr)
            {
                return stderr;
            }
            return nullptr;
        }
        /*!
         *  @brief Test whether a file descriptor refers to a terminal.
         */
        bool isAttyTerminal(const std::ostream & stream)
        {
            FILE * std_stream = getStandardStream(stream);

#if defined(OS_MACOS) || defined(OS_LINUX)
            return ::isatty(fileno(std_stream));
#elif defined(OS_WINDOWS)
            return ::_isatty(_fileno(std_stream));
#endif
        }
#if defined(OS_WINDOWS)
        void winChangeAttributes(std::ostream & stream, int foreground, int background = -1)
        {
            static WORD defaultAttributes = 0;

            // get terminal handle
            HANDLE hTerminal = INVALID_HANDLE_VALUE;
            if (&stream == &std::cout)
                hTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
            else if (&stream == &std::cerr)
                hTerminal = GetStdHandle(STD_ERROR_HANDLE);

            // save default terminal attributes if it unsaved
            if (!defaultAttributes)
            {
                CONSOLE_SCREEN_BUFFER_INFO info;
                if (!GetConsoleScreenBufferInfo(hTerminal, &info))
                    return;
                defaultAttributes = info.wAttributes;
            }

            // restore all default settings
            if (foreground == -1 && background == -1)
            {
                SetConsoleTextAttribute(hTerminal, defaultAttributes);
                return;
            }

            // get current settings
            CONSOLE_SCREEN_BUFFER_INFO info;
            if (!GetConsoleScreenBufferInfo(hTerminal, &info))
                return;

            if (foreground != -1)
            {
                info.wAttributes &= ~(info.wAttributes & 0x0F);
                info.wAttributes |= static_cast<WORD>(foreground);
            }

            if (background != -1)
            {
                info.wAttributes &= ~(info.wAttributes & 0xF0);
                info.wAttributes |= static_cast<WORD>(background);
            }

            SetConsoleTextAttribute(hTerminal, info.wAttributes);
        }
#endif
    };

public:

    ColorStdOuputLogMsg();
    ColorStdOuputLogMsg(const ColorStdOuputLogMsg & orig);
    virtual ~ColorStdOuputLogMsg();

    // @arg date_format: values are: NULL, RELATIVE, ABSOLUTE, DATE, ISO8601
    ColorStdOuputLogMsg(bool useColor, log4cxx::LogString dateFormat = "NULL");

    void setColor(bool value);
    void setPrintLocation(bool value);
    virtual void format(
        log4cxx::LogString & output, log4cxx::spi::LoggingEventPtr const & event, log4cxx::helpers::Pool & pool) const;
    virtual void setOption(const log4cxx::LogString & option, const log4cxx::LogString & value);

    std::ostream & reset(std::ostream & stream);
    std::ostream & bold(std::ostream & stream);
    std::ostream & dark(std::ostream & stream);
    std::ostream & underline(std::ostream & stream);
    std::ostream & blink(std::ostream & stream);
    std::ostream & reverse(std::ostream & stream);
    std::ostream & concealed(std::ostream & stream);
    std::ostream & grey(std::ostream & stream);
    std::ostream & red(std::ostream & stream);
    std::ostream & green(std::ostream & stream);
    std::ostream & yellow(std::ostream & stream);
    std::ostream & blue(std::ostream & stream);
    std::ostream & magenta(std::ostream & stream);
    std::ostream & cyan(std::ostream & stream);
    std::ostream & white(std::ostream & stream);
    std::ostream & onGrey(std::ostream & stream);
    std::ostream & onRed(std::ostream & stream);
    std::ostream & onGreen(std::ostream & stream);
    std::ostream & onYellow(std::ostream & stream);
    std::ostream & onBlue(std::ostream & stream);
    std::ostream & onMagenta(std::ostream & stream);
    std::ostream & onCyan(std::ostream & stream);
    std::ostream & onWhite(std::ostream & stream);

private:

    bool colorless;
    bool printLocation;
    static const char * const COLOR_TYPE[];
};

#endif
