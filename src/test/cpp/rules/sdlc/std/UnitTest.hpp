
#ifndef RULES_SDLC_STD_TEST_HPP
#define RULES_SDLC_STD_TEST_HPP

#include <vector>
#include <gmock/gmock.h>
#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::test
{
    class Test
    {

        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        Test();
        Test(std::string & suite, unsigned int iteration = 1);
        Test(const Test & orig) = default;
        virtual
        ~Test();

        int run (int argc = 0, char * argv[] = NULL);
        static void showUsage(std::string name);

    protected:

    private:

        std::string                                     m_testSuites;
        unsigned int                                    m_numberOfTestIteration;
        static const unsigned long                      LOGGER_WATCH_DELAY;
        rules::sdlc::stdc::logging::LoggingService *    m_loggerService;
    };

}
#endif
