
#ifndef COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_UNITTESTBUILDER_HPP
#define COM_GITHUB_DOEVELOPPER_RULES_SDLC_EXTENSIONS_UNITTESTBUILDER_HPP

#include <com/github/doevelopper/rules/sdlc/extensions/ConfigurableEventListener.hpp>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#define TEST_PV(testsuite, testname, ...)                                                                              \
    class testsuite##Parameterized : public testsuite,                                                                 \
                                     public ::testing::WithParamInterface<decltype(GTEST_GET_FIRST_(__VA_ARGS__))>     \
    {                                                                                                                  \
    };                                                                                                                 \
    INSTANTIATE_TEST_SUITE_P(, testsuite##Parameterized, ::testing::Values(__VA_ARGS__));                              \
    TEST_P(testsuite##Parameterized, testname)

#define ASSERT_ARRAY_NEAR(E, A, N, eps)                                                                                \
    for (size_t i = 0; i < (unsigned)(N); i++)                                                                         \
        ASSERT_NEAR((E)[i], (A)[i], (eps));

#define ASSERT_ARRAY_EQ(E, A, N)                                                                                       \
    for (size_t i = 0; i < (unsigned)(N); i++)                                                                         \
        ASSERT_EQ((E)[i], (A)[i]);

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
        void moduleUnderTest(char * argv[]);

    protected:
    private:

        std::string m_testSuites;
        std::string_view m_moduleUnderTest;
        unsigned int m_numberOfTestIteration;
        static const unsigned long LOGGER_WATCH_DELAY;
        com::github::doevelopper::rules::sdlc::logging::LoggingService * m_loggerService;
    };
}
#endif
