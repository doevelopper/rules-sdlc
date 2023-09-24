
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_UNITTESTBUILDER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_UNITTESTBUILDER_HPP

#include <com/github/doevelopper/rules/sdlc/extensions/ConfigurableEventListener.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    class UnitTestBuilder
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        UnitTestBuilder();
        UnitTestBuilder(const UnitTestBuilder &)             = delete;
        UnitTestBuilder(UnitTestBuilder &&)                  = delete;
        UnitTestBuilder & operator=(const UnitTestBuilder &) = delete;
        UnitTestBuilder & operator=(UnitTestBuilder &&)      = delete;
        virtual ~UnitTestBuilder();

        UnitTestBuilder(std::string & suite, unsigned int iteration = 1);
        int run(int argc = 0, char * argv[] = NULL);
        static void showUsage(std::string name);
        static void notYetImplemented();

    protected:
    private:

        std::string m_testSuites;
        unsigned int m_numberOfTestIteration;
        static const unsigned long LOGGER_WATCH_DELAY;
        com::github::doevelopper::rules::sdlc::logging::LoggingService * m_loggerService;
    };
}
#endif
