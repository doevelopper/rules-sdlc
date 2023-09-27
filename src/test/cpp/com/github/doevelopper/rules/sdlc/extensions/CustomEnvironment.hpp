
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_CUSTOMENVIRONMENT_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_CUSTOMENVIRONMENT_HPP

#include <com/github/doevelopper/rules/sdlc/logging/LoggingService.hpp>

#include <gtest/gtest.h>

namespace com::github::doevelopper::rules::sdlc::extensions::test
{
    class CustomEnvironment : public ::testing::Environment
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
    public:

        CustomEnvironment();
        CustomEnvironment(const CustomEnvironment &)             = delete;
        CustomEnvironment(CustomEnvironment &&)                  = delete;
        CustomEnvironment & operator=(const CustomEnvironment &) = delete;
        CustomEnvironment & operator=(CustomEnvironment &&)      = delete;
        virtual ~CustomEnvironment();

        virtual void SetUp() override; // Override this to define how to set up the environment.
        virtual void TearDown() override; // Override this to define how to tear down the environment.

    protected:
    private:
    };
}
#endif
