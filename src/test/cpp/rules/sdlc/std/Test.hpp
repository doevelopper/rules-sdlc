
#ifndef RULES_SDLC_STD_TEST_HPP
#define RULES_SDLC_STD_TEST_HPP

#include <vector>
#include <gmock/gmock.h>
#include <rules/sdlc/std/logging/LoggingService.hpp>

namespace rules::sdlc::stdc::test
{
    class UnitTest
    {

        LOG4CXX_DECLARE_STATIC_LOGGER

    public:

        UnitTest();
        UnitTest(std::string & suite, unsigned int iteration = 1);
        UnitTest(const UnitTest & orig) = default;
        virtual ~UnitTest();

        int run (int argc = 0, char * argv[] = NULL);
        static void showUsage(std::string name);

    protected:

    private:

        std::string m_testSuites;
        unsigned int m_numberOfTestIteration;
        static const unsigned long LOGGER_WATCH_DELAY;
        LoggingService *           m_loggerService;
    };

}
#endif
