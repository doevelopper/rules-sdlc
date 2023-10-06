
#include <com/github/doevelopper/rules/sdlc/extensions/UnitTestBuilder.hpp>
#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <cstdlib>

using namespace com::github::doevelopper::rules::sdlc::logging;
using namespace com::github::doevelopper::rules::sdlc::extensions::test;

/*!
 * @brief
 * @param argc number of string arguments passed via argv
 * @param argv array to command line arguments as strings
 *             (an array of character pointers)
 * @return the completion status code (zero indicates success)
 */
int main([[maybe_unused]] int argc, [[maybe_unused]] char ** argv)
{
    // char loggersConfiguratorPath[]="TEMP=/opt/log4cxx.xml";
    // putenv( loggersConfiguratorPath );

    std::uint_fast64_t runStatus = 0;

    std::cout << "argc == " << argc << '\n';

    for (int ndx {}; ndx != argc; ++ndx)
    {
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
    }

    std::cout << "argv[" << argc << "] == " << static_cast<void *>(argv[argc]) << '\n';

    try
    {
        UnitTestBuilder unit_test;

        runStatus = unit_test.run(argc, argv);

        if (runStatus != EXIT_SUCCESS)
        {
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "========== . FAILURE . ========== . FAILURE . ========== . FAILURE . =====");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), "'########::::'###::::'####:'##:::::::'########:'########::");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), " ##.....::::'## ##:::. ##:: ##::::::: ##.....:: ##.... ##:");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), " ##::::::::'##:. ##::: ##:: ##::::::: ##::::::: ##:::: ##:");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), " ######:::'##:::. ##:: ##:: ##::::::: ######::: ##:::: ##:");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), " ##...:::: #########:: ##:: ##::::::: ##...:::: ##:::: ##:");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), " ##::::::: ##.... ##:: ##:: ##::::::: ##::::::: ##:::: ##:");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), " ##::::::: ##:::: ##:'####: ########: ########: ########::");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(), "..::::::::..:::::..::....::........::........::........:::");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_ERROR(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "========== . FAILURE . ========== . FAILURE . ========== . FAILURE . =====");
            LOG4CXX_ERROR(
                log4cxx::Logger::getRootLogger(),
                "**************************************************************************");
        }
        else
        {
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                " ::::::::  :::    :::  ::::::::   ::::::::  :::::::::: ::::::::   ::::::::  ");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                ":+:    :+: :+:    :+: :+:    :+: :+:    :+: :+:       :+:    :+: :+:    :+: ");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                "+:+        +:+    +:+ +:+        +:+        +:+       +:+        +:+        ");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                "+#++:++#++ +#+    +:+ +#+        +#+        +#++:++#  +#++:++#++ +#++:++#++ ");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                "       +#+ +#+    +#+ +#+        +#+        +#+              +#+        +#+ ");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                "#+#    #+# #+#    #+# #+#    #+# #+#    #+# #+#       #+#    #+# #+#    #+# ");
            LOG4CXX_INFO(
                log4cxx::Logger::getRootLogger(),
                " ########   ########   ########   ########  ########## ########   ########  ");
            LOG4CXX_INFO(log4cxx::Logger::getRootLogger(), "");
        }
    }
    catch (const std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    catch (...)
    {
        std::cerr << "Unknown exception occured" << std::endl;
        return (EXIT_FAILURE);
    }

    return (runStatus == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
