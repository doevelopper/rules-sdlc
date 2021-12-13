
#include <rules/sdlc/std/UnitTest.hpp>
#include <rules/sdlc/std/GTestEventListener.hpp>
#include <rules/sdlc/std/ConfigurableEventListener.hpp>
#include <rules/sdlc/std/CustomEnvironment.hpp>

using namespace rules::sdlc::stdc;
using namespace rules::sdlc::stdc::logging;
using namespace rules::sdlc::stdc::test;

log4cxx::LoggerPtr UnitTest::logger =
    log4cxx::Logger::getLogger(std::string("rules.sdlc.stdc.test.UnitTest") );

const unsigned long UnitTest::LOGGER_WATCH_DELAY = 5000UL;

UnitTest::UnitTest()
    : m_testSuites(std::string())
    , m_numberOfTestIteration(1)
    , m_loggerService(new LoggingService(LOGGER_WATCH_DELAY))
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
}

UnitTest::UnitTest(std::string & suite, unsigned int iteration)
    : m_testSuites(suite)
    , m_numberOfTestIteration(iteration)
{

}

UnitTest::~UnitTest()
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    delete this->m_loggerService;
}

int UnitTest::run (int argc, char * argv[])
{
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);

    ::testing::InitGoogleTest(&argc, argv);
    //::testing::InitGoogleMock(&argc, argv);

    testing::TestEventListeners& listeners = testing::UnitTest::GetInstance()->listeners();

    auto default_printer = listeners.Release(listeners.default_result_printer());

    /*testing::TestEventListener * listener =*/ ConfigurableEventListener::Builder(default_printer)
        .showEnvironment()
        .showTestCases()
        .showTestNames()
        .showSuccesses()
        .showInlineFailures()
        .build();

    //testing::UnitTest::GetInstance()->listeners().Append(new GTestEventListener);
    listeners.Append(new GTestEventListener);
    // gtest takes ownership of the TestEnvironment ptr - we don't delete it.
    /*::testing::Environment* const env*/ ::testing::AddGlobalTestEnvironment(new CustomEnvironment);
    LOG4CXX_TRACE(logger, __LOG4CXX_FUNC__);
    int ret_val = RUN_ALL_TESTS();

    return(ret_val);
}

void UnitTest::showUsage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES \n"
              << "Options:\n"
              << "\t-h,--help \t Show this help message\n"
              << "\t-i,--iterration \t Number of iteration on test Default 1\n"
              << "\t-o,--outputpath \t Specify the destination path Default netx to executable\n"
              << "\t-m,--module \t The name of xml test report to be generated\n"
              << "\t-l,--list \t Specify the list of tests to be executed Default netx to executable\n"
              << std::endl;

}
